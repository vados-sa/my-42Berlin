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
	//start_simulation(info, fork, philo);
	cleanup(info, fork, philo);
	return (0);
}


/* void*	function(void *arg)
{
	printf("thread created\n");
	usleep(10);
	printf("finished thread\n");
	return NULL;
} */

/* if ((pthread_create(&philo[i].thread, NULL, &function, NULL)))
		{
			printf("Failed to allocate memory for philosopher %d.\n", i + 1);
			while(i-- > 0)
				pthread_join(philo[i].thread, NULL);
			free(philo);
			return (NULL);
		} */