#include "../includes/philo.h"

static void	join_threads(t_data *data);
static void	destroy_mutexes(t_data *data);

void	print_error_exit(char *message, int exit_code)
{
	printf("%s\n", message);
	exit(exit_code);
}
 
void	cleanup(t_data *data, char *message, int exit_code)
{
	if (exit_code == EXIT_SUCCESS)
	{
		join_threads(data);
		//printf("threads joined.\n");
		destroy_mutexes(data);
		//printf("mutexes destroyed.\n");
	}
	if (message)
		printf("%s\n", message);
	if (data->philo)
		free (data->philo);
	if (data->forks)
		free (data->forks);
	free(data);
	//printf("program has ended and everything is cleaned.\n");
	exit(exit_code);
}

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->nbr_of_philo)
		pthread_join(data->philo[i++].thread, NULL);
}

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->nbr_of_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->state_mutex);
}
