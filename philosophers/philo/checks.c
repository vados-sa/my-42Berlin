#include "philo.h"

int	check_starvation(t_philo *philo)
{
	uint64_t		current_time_ms;
	uint64_t		elapsed_time_ms;

	current_time_ms = get_time();
	pthread_mutex_lock(&philo->state);
	elapsed_time_ms = current_time_ms - philo->last_meal_t;
	pthread_mutex_unlock(&philo->state);
	if (elapsed_time_ms >= philo->info->time_to_die)
	{
		print_status(philo, "died");
		return (1);
	}
	return (0);
}

int	check_state(t_philo *philo)
{
	int	live;

	pthread_mutex_lock(&philo->state);
	live = philo->life_status;
	pthread_mutex_unlock(&philo->state);
	return (live);
}

int	check_meals(t_philo *philo)
{
	int	meals_done;

	pthread_mutex_lock(&philo->state);
	meals_done = philo->count_meals;
	pthread_mutex_unlock(&philo->state);
	return (meals_done);
}
