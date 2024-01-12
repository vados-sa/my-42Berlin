#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	*line;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0) //Error while reading
		return(NULL);
	line = ft_strdup(buffer);
	if (!line) //Error while duplicating the line
        return NULL;
	return (line);
}

int main()
{
	int	fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	 if (fd == -1) //Error opening file
        return 1;
	line = get_next_line(fd);
	if (line != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
	return 0;
}