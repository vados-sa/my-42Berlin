#include "philo.h"

void*	routine(void *arg)
{
	t_philo	*philo;
	int	i;

	philo = (t_philo *)arg;
	
	i = philo->info->nbr_of_meals;
	while(i > 0)
	{
		pthread_mutex_lock(&philo->print);
		printf("%d is thinking\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		printf("%d has taken the %d fork\n", philo->id, philo->id - 1);
		pthread_mutex_lock(philo->right_fork);
		printf("%d has taken the %d fork\n", philo->id, philo->id);
		printf("%d is eating\n", philo->id);
		i--;
		pthread_mutex_unlock(&philo->print);
		usleep(philo->info->time_to_eat);
		pthread_mutex_lock(&philo->print);
		printf("%d has finished eating\n", philo->id);
		printf("number of meals left for philo %d: %d\n", philo->id, i);
		pthread_mutex_unlock(&philo->print);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		//pthread_mutex_lock(&philo->print);
		//printf("%d is sleeping\n", philo->id);
		usleep(philo->info->time_to_sleep);
		//pthread_mutex_unlock(&philo->print);
		pthread_mutex_lock(&philo->print);
		printf("%d is sleeping\n", philo->id);
		pthread_mutex_unlock(&philo->print);
	}
	return (NULL);
}

void    simulation(t_elements *info, /* pthread_mutex_t *fork,  */t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->nbr_of_philo)
	{
		if ((pthread_create(&philo[i].thread, NULL, &routine, &philo[i])))
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
	while (i < info->nbr_of_philo)
		pthread_join(philo[i++].thread, NULL);
}
