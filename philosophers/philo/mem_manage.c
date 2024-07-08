#include "philo.h"

void	cleanup(t_elements *info, pthread_mutex_t *fork, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < (int)info->nbr_of_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&philo[i].print_mutex);
        pthread_mutex_destroy(&philo[i].state_mutex);
		pthread_mutex_destroy(&philo[i].meal_mutex);
		i++;
	}
	free (fork);
	free (info);
	free (philo);
}

void	error_exit(t_elements *info)
{
	free(info);
	exit (EXIT_FAILURE);
}
