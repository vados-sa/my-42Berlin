#include "philo.h"

/*The program takes as arguments: 
'number_of_philosophers', 'time_to_die', 'time_to_eat',
'time_to_sleep', and, optionally,
'[number_of_times_each_philosopher_must_eat]'*/
int	main(int ac, char *av[])
{
	t_data			*info;
	pthread_mutex_t	*fork;
	t_philo			*philo;

	if (ac != 5 && ac != 6)
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	info = init_struct();
	parse_args(ac, av, info);
	fork = init_forks(info->nbr_of_philo);
	if (!fork)
		error_exit(info);
	philo = init_philo_data(info, fork);
	if (!philo)
	{
		cleanup(info, fork, philo); // before was 'error_exit(info);'
		return (1);
	}
	simulation(philo);
	cleanup(info, fork, philo);
	return (0);
}
