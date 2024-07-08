#include "philo.h"

static void	line_to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	print_status(philo, "is eating");
}

int	eat(t_philo *philo)
{
	/* if (check_state(philo) == 1)
		return (1); */
	precise_usleep(500); // verify if really needed
	line_to_eat(philo);
	pthread_mutex_lock(&philo->meal_mutex); // maybe this block could go in the line_to_eat function
	philo->last_meal_t = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	precise_usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork); // block until here
	pthread_mutex_lock(&philo->meal_mutex);
	philo->count_meals++;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (philo->count_meals == (int)philo->info->nbr_of_meals)
		return (2);
	return (0);
}

int	nap(t_philo *philo)
{
	/* if (check_state(philo) == 1)
		return (1); */
	print_status(philo, "is sleeping");
	precise_usleep(philo->info->time_to_sleep * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	/* if (check_state(philo) == 1)
		return (1); */
	print_status(philo, "is thinking");
	precise_usleep(1); // 1000 or dependent on nbr_of_philo?
	return (0);
}
