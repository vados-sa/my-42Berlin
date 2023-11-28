/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:52:21 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/28 13:52:22 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/* #include <fcntl.h>
int main()
{
    char *message = "Hello, World!";

    // Write to standard output (stdout)
    ft_putendl_fd(message, 1);

    // Write to standard error (stderr)
    ft_putendl_fd(message, 2);

    // Write to a file (replace "output.txt" with the desired file name)
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putendl_fd(message, file_descriptor);

    // Close the file descriptor
    close(file_descriptor);

    return 0;
} */
