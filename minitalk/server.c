/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:35 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/09 17:26:45 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* void    handle_signal(int signum, siginfo_t *info, void *context)
{
    (void)info; // Unused parameter
    (void)context; // Unused parameter
	if (signal == SIGUSR1)
	{
		ft_printf("Received SIGUSR1\n");
		// do something
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("Received SIGUSR2\n");
		// do something
	}
} */

int	main()
{
	ft_printf("Server PID: %d\n", getpid());
	//signal(SIGUSR1, handle_signal);
	//signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause(); // Wait for signals
		// Perform any needed periodic checks or operations here
	}
	return (0);
}