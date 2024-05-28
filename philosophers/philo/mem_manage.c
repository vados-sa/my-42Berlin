#include "philo.h"

/* static void	clean_forks(pthread_mutex_t *fork, int quantity)
{
	int	i;

	i = 0;
	while (i < quantity)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	free (fork);
	fork = NULL;
} */

/* static void	clean_philo(t_philo *philo)
{

}  */

void	cleanup(t_elements *info, pthread_mutex_t *fork, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < (int)info->nbr_of_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		pthread_mutex_destroy(&philo[i].print);
        pthread_mutex_destroy(&philo[i].state);
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
