#include "philo.h"

void	announce_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < (int)philo->info->nbr_of_philo)
	{
		pthread_mutex_lock(&philo->state); // should maybe the lock be outside the loop?
		philo[i].life_status = DEAD;
		pthread_mutex_unlock(&philo->state);
		i++;
	}
}

int	track_meals(t_philo *philo, uint64_t total_meals)
{
	if (philo->info->nbr_of_philo == 1 || !philo->info->nbr_of_meals)
		return (0);
	if (total_meals == philo->info->nbr_of_philo * 
		philo->info->nbr_of_meals)
		return (1);
	return (0);
}
