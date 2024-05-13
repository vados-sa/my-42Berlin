#include "philo.h"

void	*monitoring(void *arg)
{
	t_philo			*philo;
	int				i;
	int				j;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->info->nbr_of_philo)
		{
			if (check_starvation(&philo[i]))
				announce_death(philo);
			//set_priority(philo, i);
			// check if forks are available;
			i++;
		}
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	gettimeofday(&philo->last_meal_t, NULL);
	while (1)
	{
		if (check_state(philo))
			break ;
		if (can_eat(philo))
		{
			eat(philo);
			if (check_state(philo))
				break ;
			nap(philo);
		}
		else
		{
			think(philo);
			while (1) // I don't yet know if this is necessary
				if (can_eat(philo))
					break ;
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
	while (i < philo->info->nbr_of_philo)
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
	while (i < philo->info->nbr_of_philo)
		pthread_join(philo[i++].thread, NULL);
	pthread_join(monitor, NULL);
}
