#include "get_next_line.h"

char *get_next_line(int fd);

char *concatenate_lines(char *l1, char *l2);

char *concatenate_lines(char *l1, char *l2)
{
	char	*new_line;

	new_line = ft_strjoin(l1, l2);
	if (!new_line)
		return NULL;
	return (new_line);
}

char *get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	int				bytes_read;
	static char		*line;
	char			*temp_line;

	bytes_read = 0;
	line = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytes_read < 0) //Error while reading
			return(NULL);
		temp_line = ft_strdup(buffer);
		if (!temp_line) //Error while duplicating the line
    	    return NULL;
		line = concatenate_lines(line, temp_line);
		if (!line)
			return NULL;
		free (temp_line);
	}
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