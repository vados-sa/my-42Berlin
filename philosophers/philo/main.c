#include "philo.h"

/*The program takes as arguments: 
'number_of_philosophers', 'time_to_die', 'time_to_eat',
'time_to_sleep', and, optionally,
'[number_of_times_each_philosopher_must_eat]'*/
int	main(int ac, char *av[])
{
	t_elements	*info;
	t_philo		*philo;

	if (ac != 5 && ac != 6)
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	info = init_struct();
	parse_args(ac, av, info);
	philo = init_philo(info);
	philosophers(philo);
	free (info);
	free (philo);
	return (0);
}
