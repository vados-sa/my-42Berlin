/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:20:57 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/17 17:40:56 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * Validates the command line arguments.
 */
static void	parse_args(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		print_error_exit("Wrong number of arguments!", EXIT_FAILURE);
	if ((int)ft_custom_atoi(av[1]) <= 0 || (int)ft_custom_atoi(av[2]) <= 0 || 
		(int)ft_custom_atoi(av[3]) <= 0 || (int)ft_custom_atoi(av[4]) <= 0)
		print_error_exit("All values must be positive!", EXIT_FAILURE);
	if (ac == 6)
		if ((int)ft_custom_atoi(av[5]) <= 0)
			print_error_exit("All values must be positive!", EXIT_FAILURE);
}

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
