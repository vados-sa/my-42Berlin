/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:22:14 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/10 09:31:01 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	check_pid(char *pid, int server_pid);
static void	check_arguments(int ac, char *av);
static void	handle_acknow_signal(int sig);
static void	send_pid(int client_pid, int server_pid);

static int	g_ack_received = 0;

static void	check_pid(char *pid, int server_pid)
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
	if (server_pid <= 0)
	{
		ft_printf("\nInvalid PID.\n\nIt should be a positive number!\n\n");
		exit(1);
	}
}

static void	check_arguments(int ac, char *av)
{
	if (ac != 3)
	{
		ft_printf("\nOpsie! Wrong format!\n\n");
		ft_printf("Proper usage: %s <PID> \"Message\"\n\n", av);
		exit(1);
	}
}

static void	handle_acknow_signal(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

static void	send_pid(int client_pid, int server_pid)
{
	char	*c_pid_str;
	int		i;

	c_pid_str = ft_itoa(client_pid);
	if (!c_pid_str)
		error_exit();
	i = 0;
	while (c_pid_str[i])
	{
		send_bit(c_pid_str[i], server_pid);
		i++;
	}
	free(c_pid_str);
	send_bit((char)4, server_pid);
}

/* av[1]: server's PID. av[2]: message to be sent. */
int	main(int ac, char *av[])
{
	int	i;
	int	server_pid;
	int	client_pid;

	check_arguments(ac, av[0]);
	i = 0;
	server_pid = ft_atoi(av[1]);
	check_pid(av[1], server_pid);
	signal(SIGUSR1, handle_acknow_signal);
	client_pid = getpid();
	send_pid(client_pid, server_pid);
	while (av[2][i])
	{
		send_bit(av[2][i], server_pid);
		i++;
	}
	send_bit((char)4, server_pid);
	while (!g_ack_received)
		pause();
	ft_printf("\nMessage received by the server successfully!\n\n");
	return (0);
}
