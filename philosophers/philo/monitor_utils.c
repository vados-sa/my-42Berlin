#include "philo.h"

void	announce_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->nbr_of_philo)
		philo[i++].is_live = 1;
}

void	set_priority(t_philo *philo, int i)
{
	
}
