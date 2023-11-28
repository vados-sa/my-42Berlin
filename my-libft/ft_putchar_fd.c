/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:51:59 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/28 13:52:00 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/* #include <fcntl.h>
int	main()
{
	char letter = 'A';

    // Write to standard output (stdout)
    ft_putchar_fd(letter, 1);

    // Write to standard error (stderr)
    ft_putchar_fd(letter, 2);

    // Write to a file (replace "output.txt" with the desired file name)
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putchar_fd(letter, file_descriptor);

    // Close the file descriptor
    close(file_descriptor);

	return (0);
} */