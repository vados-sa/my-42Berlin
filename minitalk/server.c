/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:00:35 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/05 14:59:07 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* getpid(): Returns the process ID (PID) of the calling process. 
This is often used by the server to print its PID, which clients 
need to communicate with it.
To find the server's PID, you can use the getpid() function within your
server program and print the result. This PID must then be provided
to the client as an argument so it knows where to send its messages.
 */
int	main()
{
	// Setup signal handler
    //signal(SIGUSR1, signal_handler);
    //signal(SIGUSR2, signal_handler);
    
    // Print the server's PID
    printf("Server PID: %d\n", getpid()); // change to ft_printf
    
    // Main loop
    //while (1) {
    //    pause(); // Wait for signals
    //}
    
	return (0);
}