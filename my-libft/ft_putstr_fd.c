#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* #include <fcntl.h>
int main()
{
    char *message = "Hello, World!\n";

    // Write to standard output (stdout)
    ft_putstr_fd(message, 1);

    // Write to standard error (stderr)
    ft_putstr_fd(message, 2);

    // Write to a file (replace "output.txt" with the desired file name)
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putstr_fd(message, file_descriptor);

    // Close the file descriptor
    close(file_descriptor);

    return 0;
} */