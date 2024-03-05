/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:11 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/05 15:36:07 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
* av[1]: server's PID.
* av[2]: message to be sent
*/
int	main(int ac, char *av[])
{
	int	i;
	
	if (ac != 3)
		printf("Wrong format!\n");
	i = 0;
	while (av[1][i])
	{
		if(!ft_isdigit(av[1][i]))
		{
			ft_printf("Incorrect PID.\nPID should only have digits.\n");
			exit ;
		}
		i++;
	}
	// process the message to be sent to server.
	return (0);
}
