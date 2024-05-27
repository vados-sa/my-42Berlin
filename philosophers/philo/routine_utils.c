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
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	philo->last_meal_t = get_time();
	precise_usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->state);
	 philo->count_meals++;
	pthread_mutex_unlock(&philo->state);
	if (philo->count_meals == (int)philo->info->nbr_of_meals)
		return (2);
	return (0);
}

int	nap(t_philo *philo)
{
	if (check_state(philo) == 1)
		return (1);
	print_status(philo, "is sleeping");
	precise_usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	if (check_state(philo) == 1)
		return (1);
	print_status(philo, "is thinking");
	precise_usleep(1);
	return (0);
}
