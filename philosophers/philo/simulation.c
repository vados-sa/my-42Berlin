#include "philo.h"

void*	monitoring(void *arg) // maybe move into monitoring.c
{
	t_philo			*philo;
	struct timeval	now;
	long			time_elapsed;
	int				i;

	philo = (t_philo *)arg;
	now.tv_sec = 0;
	now.tv_usec = 0;
	while(1)
	{
		i = 0;
		while(i < philo->info->nbr_of_philo)
		{ //maybe make this a function
			gettimeofday(&now, NULL);
			time_elapsed = (now.tv_sec - philo[i].last_meal_t.tv_sec) * 1000 \
			+ (now.tv_usec - philo[i].last_meal_t.tv_usec) / 1000;
			if (time_elapsed > philo[i].info->time_to_die)
			{
				printf("%lu %d died\n", now.tv_sec * 1000 + now.tv_usec / 1000, \
				philo[i].id);
				i = 0;
				while(i < philo[i].info->nbr_of_philo)
					philo[i].is_live = 1;
				return (NULL);
			}
			// check for is forks are available;
			// give priority to philosophers;
			i++;
		}
	}
	return (NULL);
}

void*	dinner(void *arg) // maybe move into dinner.c
{
	t_philo	*philo;
	int	i;

	philo = (t_philo *)arg;
	gettimeofday(&philo->last_meal_t, NULL);
	i = philo->info->nbr_of_meals;
	while(!philo->is_live /* && i > 0 */) // check if it can eat, otherwise it thinks
	{
		pthread_mutex_lock(&philo->print);  // LOCK PRINT
		printf("%d is thinking\n", philo->id);
		// check if it is its turn to eat || or if it has not starved;
		pthread_mutex_lock(philo->left_fork);
		printf("%d has taken the %d fork\n", philo->id, philo->id - 1);
		pthread_mutex_lock(philo->right_fork);
		printf("%d has taken the %d fork\n", philo->id, philo->id);
		printf("%d is eating\n", philo->id);
		pthread_mutex_unlock(&philo->print);  // UNLOCK PRINT
		gettimeofday(&philo->last_meal_t, NULL);
		usleep(philo->info->time_to_eat / 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->print);
		printf("%d is sleeping\n", philo->id);
		usleep(philo->info->time_to_sleep / 1000);
		pthread_mutex_unlock(&philo->print);
	}
	return (NULL);
}

void    simulation(t_philo *philo)
{
	pthread_t	monitor;
	int			i;
	int			j;

	pthread_create(&monitor, NULL, &monitoring, philo);
	i = 0;
	while (i < philo->info->nbr_of_philo)
	{
		if ((pthread_create(&philo[i].thread, NULL, &dinner, &philo[i])))
		{
			printf("Failed to allocate memory for philosopher %d.\n", i + 1);
			j = 0;
			while(j < i)
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
