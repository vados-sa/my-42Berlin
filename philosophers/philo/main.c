#include "philo.h"

int	main(int ac, char *av[])
{
	t_data			*data;
	
	parse_args(ac, av);
	data = init_data(ac, av);
	simulation(data);
	monitor(data);
	cleanup(data, NULL, 0);
	return (0);
}
