#include "../includes/philo.h"

static int	check_state(t_philo *philo);
static void	line_to_eat(t_philo *philo);

int	eat(t_philo *philo)
{
	if (check_state(philo) == DEAD)
		return (1);
	line_to_eat(philo);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_t = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	precise_usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->count_meals++;
	if (philo->count_meals == philo->nbr_of_meals)
	{
		//philo->full = FULL;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		return (2);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (0);
}

int	nap(t_philo *philo)
{
	if (check_state(philo) == DEAD)
		return (1);
	print_status(philo, "is sleeping");
	precise_usleep(philo->time_to_sleep * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	if (check_state(philo) == DEAD)
		return (1);
	print_status(philo, "is thinking");
	precise_usleep(1000); // 1000 or dependent on nbr_of_philo?
	return (0);
}

static int	check_state(t_philo *philo)
{
	int	live;

	pthread_mutex_lock(&philo->data->state_mutex);
	live = philo->life_status;
	pthread_mutex_unlock(&philo->data->state_mutex);
	return (live);
}

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
