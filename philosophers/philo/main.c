#include "philo.h"

/*The program takes as arguments: 'number_of_philosophers', 'time_to_die',
'time_to_eat', 'time_to_sleep', and, optionally, '[number_of_times_each_philosopher_must_eat]'*/
int	main(int ac, char *av[])
{
	if (ac == 5)
	{
		// handle program without 'number_of_times_each_philosophers_must_eat'
	}
	else if (ac == 6)
	{
		// handle program with 'number_of_times_each_philosophers_must_eat'
	}
	else
	{
		printf("Wrong number of arguments");
		return (1);
	}
	return (0);
}
