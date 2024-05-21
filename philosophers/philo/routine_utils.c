#include "philo.h"

/* int	can_eat(t_philo *philo)
{
	// Question 1: are both forks available?
	// Question 2: o I have priority?
	// If (1 && 2 are true)
	//		return (1);
	return (0);
} */

int	eat(t_philo *philo)
{
	if (check_state(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->print);
	/* printf("%" PRIu64 " %d has taken a fork\n", \
	(get_time() - philo->info->start_time), philo->id); */
	printf("%" PRIu64 " %d has taken the %d fork\n", (get_time() - \
	philo->info->start_time), philo->id, philo->id - 1);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->print);
	/* printf("%" PRIu64 " %d has taken a fork\n", \
	(get_time() - philo->info->start_time), philo->id); */
	printf("%" PRIu64 " %d has taken the %d fork\n", (get_time() - \
	philo->info->start_time), philo->id, philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->print);
	printf("%" PRIu64 " %d is eating\n", (get_time() - \
	philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->print);
	philo->last_meal_t = get_time();
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	nap(t_philo *philo)
{
	if (check_state(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->print);
	printf("%" PRIu64 " %d is sleeping\n", (get_time() - \
	philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->print);
	usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	if (check_state(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->print);
	printf("%" PRIu64 " %d is thinking\n", (get_time() - \
	philo->info->start_time), philo->id);
	pthread_mutex_unlock(&philo->print);
	usleep(1);
	return (0);
}


