#include "philo.h"

void	*monitoring(void *arg)
{
	t_philo			*philo;
	int				i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < (int)philo->info->nbr_of_philo)
		{
			if (check_starvation(&philo[i]) == 1)
			{
				announce_death(philo);
				return (NULL);
			}
			if (philo->info->nbr_of_philo > 1)
				set_priority(philo, philo->info->nbr_of_philo);
			// check if forks are available;
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
		if (check_state(philo) == 1)
			break ;
		if (check_if_can_eat(philo))
		{
			eat(philo);
			if (check_state(philo) == 1)
				break ;
			nap(philo);
		}
		else
		{
			think(philo);
			while (check_if_can_eat(philo) == 0)
				continue ;
		}
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
