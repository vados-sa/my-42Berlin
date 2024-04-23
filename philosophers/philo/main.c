#include "philo.h"

/*The program takes as arguments: 'number_of_philosophers', 'time_to_die',
'time_to_eat', 'time_to_sleep', and, optionally, '[number_of_times_each_philosopher_must_eat]'*/
int	main(int ac, char *av[])
{
	int	optional_arg; // flag for 'number_of_times_each_philosophers_must_eat'

	optional_arg = 0;
	if (ac == 5 || ac == 6)
	{
		if (ac == 6)
			optional_arg = 1;
		
	}
	else
	{
		printf("Wrong number of arguments");
		return (1);
	}
	return (0);
}
