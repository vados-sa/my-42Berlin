#include "get_next_line.h"

char *get_next_line(int fd);

char *concatenate_lines(char *l1, char *l2);

//I think I have to concatanate what was read after the '\n' with the next bytes read.
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
	char			*temp_line;
	static char		*line;

	line = ft_strdup("");
	if (!line)
    	return NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0) //Error while reading or there is nothing else to read
		return(NULL);
	buffer[bytes_read] = '\0';
	temp_line = ft_strdup(buffer);
	if (!temp_line) //Error while duplicating the line
		return NULL;
	line = concatenate_lines(line, temp_line);
	free (temp_line); //Free temp buffer to allow space for the next read
	return (line);
}

int main()
{
	int		fd;
	int		i;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
	 if (fd == -1) //Error opening file
		return 1;
	i = 1;
	while ((line = get_next_line(fd)) != NULL) //Repeated calls to read the text file, one line at a time
	{
		printf("line %d: %s", i, line);
		free(line); //Free each line obtained from get_next_line
		i++;
	}
	close(fd);
	return 0;
}