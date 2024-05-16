#include "philo.h"

/* int	can_eat(t_philo *philo)
{
	// Question 1: are both forks available?
	// Question 2: o I have priority?
	// If (1 && 2 are true)
	//		return (1);
	return (0);
} */

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->print);
	printf("%.1f %d has taken the %d fork\n", (double)(get_time() - philo->info->start_time), philo->id, philo->id - 1);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->print);
	printf("%.1f %d has taken the %d fork\n", (double)(get_time() - philo->info->start_time), philo->id, philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->print);
	printf("%.1f %d is eating\n", (double)(get_time() - philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->print);
	philo->last_meal_t = get_time();
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	nap(t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	printf("%.1f %d is sleeping\n", (double)(get_time() - philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->info->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (check_state(philo))
		return ;
	pthread_mutex_lock(&philo->print);
	printf("%.1f %d is thinking\n", (double)(get_time() - philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->print);
}


