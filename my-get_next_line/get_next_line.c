#include "get_next_line.h"

char *get_next_line(int fd);
char *read_line(char *, char *, int fd);
char *set_line(char *line);

char *set_line(char *line)
{
	int		i;
	char	*final_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
	{
		final_line = ft_substr(line, 0, i);
		if (!final_line)
			return NULL;
		free (line);
		return (final_line);
	}
	return(line); //check if I have to return a duplicate
}

//This funtion reads the line until it finds \n or \0, and concatenate the strings.
char *read_line(char *left_part, char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	while (ft_strchr(left_part, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && *left_part == '\0') //Error while reading or there is nothing else to read
			return (NULL);
		else if (bytes_read <= 0 && *left_part != '\0') //there is probably a better way of doing this
			return (left_part); //check if it is null terminated. !!
		buffer[bytes_read] = '\0'; //check for redundancy. !!
		temp = left_part;
		left_part = ft_strjoin(temp, buffer);
		free(temp);
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
	char			buffer[BUFFER_SIZE + 1]; //+1 for the null-terminating.
	char			*line;

	if (fd < 0) //Error opening file
		return NULL;
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	line = read_line(left_part, buffer, fd);
	if (!line)
		return NULL;
	right_part = ft_strchr(line, '\n');
	printf("%s\n", right_part);
	if (right_part != NULL)
	{
		right_part++;
		left_part = ft_substr(line, right_part - line, ft_strlen(right_part)); //separates what comes after '\n'
		if (!left_part)           //This expression calculates the difference between the two pointers.
			return NULL;	       //It represents the distance (number of characters) between line and right_part.
	}
	line = set_line(line); 
	return (line);
}

int main()
{
	int		fd;
	int		i;
	char 	*line;

	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (1) //Repeated calls to read the text file, one line at a time
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line %d: %s", i, line);
		if (line == NULL)
			break;
		i++;
		free(line); //Free each line obtained from get_next_line
	}
	close(fd);
	return 0;
}