#include "philo.h"

int	check_starvation(t_philo *philo)
{
	uint64_t		current_time_ms;
	uint64_t		elapsed_time_ms;

	current_time_ms = get_time();
	elapsed_time_ms = current_time_ms - philo->last_meal_t;
	if (elapsed_time_ms >= philo->info->time_to_die)
	{
		//announce_death(philo);
		pthread_mutex_lock(&philo->print);
		printf("%" PRIu64 " %d died\n", (current_time_ms - philo->info->start_time), philo->id);
		pthread_mutex_unlock(&philo->print);
		return (1);
	}
	return (0);
}

int	check_state(t_philo *philo)
{
	int live;

	pthread_mutex_lock(&philo->state);
	live = philo->is_live;
	pthread_mutex_unlock(&philo->state);
	if (live == 1)
		return (1);
	return (0);
}

int	check_if_can_eat(t_philo *philo)
{
	int	eat;
	
	pthread_mutex_lock(&philo->state);
	eat = philo->priority;
	pthread_mutex_unlock(&philo->state);
	if (eat == 1)
		return (1);
	return (0);
}
