#include "philo.h"

void	error_exit(t_elements *info)
{
	free(info);
	exit (1);
}
