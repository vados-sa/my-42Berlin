#include "philo.h"

void	*monitoring(void *arg)
{
	t_philo		*philo;
	int			i;
	int			starved;
	uint64_t	total_meals;

	philo = (t_philo *)arg;
	total_meals = 0;
	while (1)
	{
		i = 0;
		while (i < (int)philo->info->nbr_of_philo)
		{
			starved = check_starvation(&philo[i]);
			if (starved)
			{
				pthread_mutex_lock(&philo->state);
				announce_death(philo);
				pthread_mutex_unlock(&philo->state);
				return (NULL);
			}
			total_meals += check_meals(&philo[i]);
			i++;
		}
		if (total_meals == philo->info->nbr_of_philo * 
			philo->info->nbr_of_meals)
			return (NULL);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_t = get_time();
	precise_usleep(1000);
	while (1)
	{
		if (eat(philo))
			return (NULL);
		if (nap(philo))
			return (NULL);
		if (think(philo))
			return (NULL);
	}
	return (NULL);
}

void	simulation(t_philo *philo)
{
	pthread_t	monitor;
	int			i;
	int			j;

	pthread_create(&monitor, NULL, &monitoring, philo);
	i = 0;
	while (i < (int)philo->info->nbr_of_philo)
	{
		if ((pthread_create(&philo[i].thread, NULL, &routine, &philo[i])))
		{
			printf("Failed to allocate memory for philosopher %d.\n", i + 1);
			j = 0;
			while (j < i)
				pthread_join(philo[j++].thread, NULL);
			return ;
		}
		i++;
	}
	i = 0;
	pthread_join(monitor, NULL);
	while (i < (int)philo->info->nbr_of_philo)
		pthread_join(philo[i++].thread, NULL);
}
