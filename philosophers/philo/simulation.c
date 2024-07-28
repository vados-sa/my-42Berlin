#include "philo.h"

static void	*routine(void *arg);

void	simulation(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < (int)data->nbr_of_philo)
	{
		pthread_mutex_lock(&data->meal_mutex);
		data->philo[i].last_meal_t = get_time();
		pthread_mutex_unlock(&data->meal_mutex);
		if ((pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i])))
		{
			printf("Failed to create Philosopher %d.\n", i + 1);
			j = 0;
			while (j < i)
				pthread_join(data->philo[j++].thread, NULL);
			cleanup(data, NULL, EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < (int)data->nbr_of_philo)
		pthread_join(data->philo[i++].thread, NULL);
}

static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_t = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	precise_usleep(1000); // check later if necessary
	if (philo->data->nbr_of_philo != 1)
	{
		while (1)
		{
			if (eat(philo))
				return (NULL);
			if (nap(philo))
				return (NULL);
			if (think(philo))
				return (NULL);
		}
	}
	return (NULL);
}
