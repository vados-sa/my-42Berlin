#include "philo.h"

static void	clean_forks(pthread_mutex_t *fork, int quantity)
{
	int	i;

	i = 0;
	while(i < quantity)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	free (fork);
	fork = NULL;
}

/* static void	clean_philo(t_philo *philo)
{

}  */

void	cleanup(t_elements *info, pthread_mutex_t *fork, t_philo *philo)
{
	clean_forks(fork, info->nbr_of_philo);
	free (info);
	free (philo);
	//clean_philo(philo);
} 

void	error_exit(t_elements *info)
{
	free(info);
	exit (EXIT_FAILURE);
}
