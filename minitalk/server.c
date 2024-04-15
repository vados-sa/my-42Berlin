/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:35 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/15 10:37:49 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int sig)
{
	static unsigned char	byte;
	static int				bit_count;

	if (sig == SIGUSR1)
		byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (byte == 4)
		{
			byte = 0;
			bit_count = 0;
			return ;
		}
		write(1, &byte, 1);
		byte = 0;
		bit_count = 0;
	}
}

static void	receive_signal(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
}

int	main(void)
{
	ft_printf("Server running with PID: %d\n", getpid());
	while (1)
		receive_signal();
	return (0);
}
