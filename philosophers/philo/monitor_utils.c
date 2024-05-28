#include "philo.h"

void	announce_death(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->state);
	while (i < (int)philo->info->nbr_of_philo)
		philo[i++].life_status = DEAD;
	pthread_mutex_unlock(&philo->state);
}

int	track_meals(t_philo *philo, uint64_t total_meals)
{
	if (philo->info->nbr_of_philo == 1)
		return (0);
	if (total_meals == philo->info->nbr_of_philo * 
		philo->info->nbr_of_meals)
		return (1);
	return (0);
}
