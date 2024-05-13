#include "philo.h"

int	check_starvation(t_philo *philo)
{
	struct timeval	now;
	double		current_time_ms;
	double		elapsed_time_ms;

	now.tv_sec = 0;
	now.tv_usec = 0;
	gettimeofday(&now, NULL);
	current_time_ms = (double)(now.tv_sec - philo->info->start_time.tv_sec) * \
	1000.0 + (double)(now.tv_usec - philo->info->start_time.tv_usec) / 1000.0;
	elapsed_time_ms = (double)(now.tv_sec - philo->last_meal_t.tv_sec) * \
	1000.0 + (double)(now.tv_usec - philo->last_meal_t.tv_usec) / 1000.0;
	if (elapsed_time_ms >= philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->print);
		printf("%.2f %d died\n", current_time_ms, philo->id);
		pthread_mutex_unlock(&philo->print);
		return (1);
	}
	return (0);
}

int	check_state(t_philo *philo)
{
	int live;

	//live = 0;
	pthread_mutex_lock(&philo->state);
	live = philo->is_live;
	pthread_mutex_unlock(&philo->state);
	if (live)
		return (1);
	return (0);
}

int	check_forks(t_philo *philo)
{
	
	return (0);
}
