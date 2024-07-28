#include "philo.h"

static void	destroy_threads(t_data *data);
 
void	cleanup(t_data *data, char *message, int exit_code)
{
	if (exit_code == EXIT_SUCCESS)
		destroy_threads(data);
	if (message)
		printf("%s\n", message);
	if (data->philo)
		free (data->philo);
	if (data->forks)
		free (data->forks);
	free(data);
	exit(exit_code);
}

static void	destroy_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->nbr_of_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->state_mutex);
}
