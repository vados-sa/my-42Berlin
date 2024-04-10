/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:29:46 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/10 09:29:47 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	get_client_pid(unsigned char byte, int *flag);
static void	send_acknowledgement(int pid);
static void	handle_signal(int sig);

static int	get_client_pid(unsigned char byte, int *flag)
{
	static char		pid_buffer[11];
	static int		i;
	static int		client_pid;

	if (*flag == 0)
	{
		pid_buffer[i] = byte;
		if (byte == 4)
		{
			pid_buffer[i] = '\0';
			client_pid = ft_atoi(pid_buffer);
			*flag = 1;
			i = 0;
			return (client_pid);
		}
		i++;
	}
	return (0);
}

static void	send_acknowledgement(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
		error_exit();
}

static void	handle_signal(int sig)
{
	static unsigned char	byte;
	static int				bit_count;
	static int				flag;
	static int				client_pid;

	if (sig == SIGUSR1)
		byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (flag == 0)
			client_pid = get_client_pid(byte, &flag);
		else if (flag == 1 && byte != 4)
			write(1, &byte, 1);
		else if (byte == 4 && flag == 1)
		{
			byte = 0;
			bit_count = 0;
			flag = 0;
			send_acknowledgement(client_pid);
			return ;
		}
		byte = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("Server running with PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
