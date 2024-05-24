#include "philo.h"

void	*monitoring(void *arg)
{
	t_philo		*philo;
	int			i;
	int			starved;

	philo = (t_philo *)arg;
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
			i++;
		}
		//usleep (10000);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_t = get_time();
	while (1)
	{
		if (eat(philo) == 1)
			return (NULL);
		if (nap(philo) == 1)
			return (NULL);
		if (think(philo) == 1)
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
