#include "philo.h"

int	check_starvation(t_philo *philo)
{
	uint64_t		current_time_ms;
	uint64_t		elapsed_time_ms;

	current_time_ms = get_time();
	elapsed_time_ms = current_time_ms - philo->last_meal_t;
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
	if (live == 1)
		return (1);
	return (0);
}

int	check_meals(t_philo *philo)
{
	int	meals_done;
	
	meals_done = philo->count_meals;
	return(meals_done);
}
