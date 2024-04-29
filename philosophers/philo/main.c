#include "philo.h"

/*The program takes as arguments: 
'number_of_philosophers', 'time_to_die', 'time_to_eat',
'time_to_sleep', and, optionally,
'[number_of_times_each_philosopher_must_eat]'*/
int	main(int ac, char *av[])
{
	t_elements	*info;

	if (ac != 5 && ac != 6)
	{
		printf("Wrong number of arguments!\nUsage: %s number_of_philosophers \
		time_to_die time_to_eat time_to_sleep \
		[number_of_times_each_philosopher_must_eat]\n", av[0]);
		return (1);
	}
	info = init_struct();
	parse_args(ac, av, info);
	if (info->nbr_of_philo == 1) // should I stay or should I go?
	{
		printf("Warning: Only one philosopher present.\
 They will not be able to eat and will die.\n");
		free (info);
		return (0);
	}
	free (info);
	return (0);
}
