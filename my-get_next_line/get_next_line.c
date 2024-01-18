#include "get_next_line.h"

char *get_next_line(int fd);
char *read_the_line(char *, char *, int fd);
char *set_line(char *line);

char *set_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
	{
		line = ft_substr(line, 0, i);
		return (line);
	}
	return(line); //check if I have to return a duplicate
}

//This funtion reads the line until it finds \n or \0, and concatenate the strings.
char *read_the_line(char *left_part, char *buffer, int fd)
{
	int		bytes_read;

	while (ft_strchr(left_part, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && *left_part == '\0') //Error while reading or there is nothing else to read
			return (NULL);
		else if (bytes_read <= 0 && *left_part != '\0') //there is probably a better way of doing this
			return (left_part);
		buffer[bytes_read] = '\0';
		left_part = ft_strjoin(left_part, buffer);
		if (!left_part)
			return(NULL);
		if (ft_strchr(left_part, '\n') != 0) //If it finds '\n'
			break; //break to return the whole line.
	}
	return (left_part);
}

char *get_next_line(int fd)
{
	static char		*left_part;
	char			*right_part;
	char			buffer[BUFFER_SIZE];
	char			*line;

	if (fd < 0) //Error opening file
		return NULL;
	line = read_the_line(left_part, buffer, fd);
	if (!line)
		return NULL;
	right_part = ft_strchr(line, '\n');
	if (right_part != NULL)
		left_part = ft_substr(line, right_part - line + 1, BUFFER_SIZE); //separates what comes after '\n'
	line = set_line(line);          //This expression calculates the difference between the two pointers. It represents the distance (number of characters) between line and right_part.
	return (line);
}

int main()
{
	int		fd;
	int		i;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
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