/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:35 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/14 14:34:22 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

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
			//write(1, "\n", 1);
			return ;
		}
		write(1, &byte, 1);
		byte = 0;
		bit_count = 0;
	}
}

/* #define MAX_MESSAGE_LENGTH 1024

static void    handle_signal(int sig)
{
	static unsigned char	byte;
	static int				bit_count;
	static char message[MAX_MESSAGE_LENGTH];
    static int message_length;

	if (sig == SIGUSR1) // bit 1;
		byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (byte == 4 || message_length == MAX_MESSAGE_LENGTH - 1)
		{
			message[message_length] = '\0';
			ft_printf("%s", message);
            ft_memset(message, 0, MAX_MESSAGE_LENGTH);
            message_length = 0;
			if (byte == 4)
			{
				write(1, "\n", 1);
                return ;
			}
		}
		else
			message[message_length++] = byte;
		byte = 0;
		bit_count = 0;
	}
} */

int	main(void)
{
	ft_printf("Server running with PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
