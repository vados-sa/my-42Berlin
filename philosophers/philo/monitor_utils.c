#include "philo.h"

void	announce_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < (int)philo->info->nbr_of_philo)
		philo[i++].life_status = DEAD;
}

static int	find_longest_wait(t_philo *philo, int nbr_of_philos)
{
	int			philo_index;
	int			i;
	uint64_t	max_time;
	uint64_t	current_time;

	philo_index = 0;
	max_time = philo[0].last_meal_t;
	i = 1;
	while (i < nbr_of_philos)
	{
		current_time = philo[i].last_meal_t;
		if (current_time < max_time)
		{
			max_time = current_time;
			philo_index = i;
		}
		i++;
	}
	return (philo_index);
}

void	set_priority(t_philo *philo, int nbr_of_philos)
{
	int			i;
	int			philo_index;

	pthread_mutex_lock(&philo->state);
	philo_index = find_longest_wait(philo, nbr_of_philos);
	i = 0;
	while (i < nbr_of_philos)
	{
		if (i == philo_index)
			philo[i].priority = 1;
		else
			philo[i].priority = 0;
		i++;
	}
	pthread_mutex_unlock(&philo->state);
}
