#include "philo.h"

/*The program takes as arguments: 
'number_of_philosophers', 'time_to_die', 'time_to_eat',
'time_to_sleep', and, optionally,
'[number_of_times_each_philosopher_must_eat]'*/
int	main(int ac, char *av[])
{
	t_elements		*info;
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
		error_exit(info);
	simulation(philo);
	cleanup(info, fork, philo);
	printf("%" PRIu64 " Program ends\n", (get_time() - \
	philo->info->start_time));
	return (0);
}
