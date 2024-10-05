/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:20:57 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/05 15:20:58 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
