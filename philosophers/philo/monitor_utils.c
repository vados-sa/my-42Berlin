#include "philo.h"

void	announce_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < (int)philo->info->nbr_of_philo)
		philo[i++].life_status = DEAD;
}
