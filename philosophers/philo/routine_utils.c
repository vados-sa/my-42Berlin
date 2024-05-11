#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->print);
	printf("%d has taken the %d fork\n", philo->id, philo->id - 1);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->print);
	printf("%d has taken the %d fork\n", philo->id, philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->print);
	printf("%d is eating\n", philo->id);
	pthread_mutex_unlock(&philo->print);
	gettimeofday(&philo->last_meal_t, NULL);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	nap(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	printf("%d is sleeping\n", philo->id);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->info->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);  // LOCK PRINT
	printf("%d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->print);
}


