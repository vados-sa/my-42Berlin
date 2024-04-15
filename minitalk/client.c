/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:11 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/15 10:38:50 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

static void	error_exit(void)
{
	ft_printf("\nError\n\n");
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
		usleep(100);
		i--;
	}
}

static void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_printf("\nInvalid PID.\n\nIt should only contain digits!\n\n");
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

	if (ac != 3)
	{
		ft_printf("\nOpsie! Wrong format!\n\n");
		ft_printf("Proper usage: %s <PID> \"Message\"\n\n", av[0]);
		return (1);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("\nInvalid PID.\n\nIt should be a positive number!\n\n");
		return (1);
	}
	check_pid(av[1]);
	while (av[2][i])
	{
		send_bit(av[2][i], pid);
		i++;
	}
	send_bit((char)4, pid);
	return (0);
}
