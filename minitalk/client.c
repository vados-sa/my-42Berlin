/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:11 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/09 17:14:31 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	send_bit(char c, int pid)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_exit();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_exit();
		}
		usleep(100); //verify if the delay is adequate
		i--;
	}
}

void	check_input(int ac, char *pid)
{
	int	i;

	if (ac != 3)
	{
		ft_printf("Wrong format!\n");
		ft_printf("Please insert this way: ./client <PID> message\n");
		exit(1);
	}
	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf("Invalid PID.\nIt should only contain digits!\n");
			exit(1);
		}
		i++;
	}
}

/* av[1]: server's PID. av[2]: message to be sent. */
int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
	    ft_printf("Invalid PID.\nIt should be a positive number!\n");
	    exit(1);
	}
	check_input(ac, av[1]);
	while (av[2][i])
	{
		send_bit(av[2][i], pid);
		i++;
	}
	send_bit((char)4, pid); //ASCII decimal = 4: EOT (End of Transmition) to indicate the end of messege.
	return (0);
}
