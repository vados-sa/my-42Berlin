/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:35 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/12 15:29:29 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

void    handle_signal(int sig)
{
	static unsigned char	byte;
	static int				bit_count;

	if (sig == SIGUSR1) // bit 1;
		byte |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (byte == 4)
		{
			
			exit(0);
		}
		ft_printf("%c", byte); //print each byte until the message it's over.
        byte = 0;
		bit_count = 0;
	}
}

int	main()
{
	ft_printf("Server running with PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}