#include "get_next_line.h"

char *get_next_line(int fd);
char *read_line(char *, char *, int fd);
char *set_line(char *line);

char *set_line(char *line)
{
	char	*final_line;
	char	*newline_ptr;

	final_line = NULL;
	newline_ptr = ft_strchr(line, '\n');
	if (newline_ptr)
	{
		final_line = ft_substr(line, 0, newline_ptr - line + 1);
		if (!final_line)
		{
			free (line);
			return NULL;
		}
	}
	else
	{
		final_line = ft_strdup(line);
		if (!final_line)
		{
			free (line);
			return NULL;
		}
	}
	free (line);
	return (final_line);
}

//This funtion reads the line until it finds \n or \0, and concatenate the strings.
char *read_line(char *left_part, char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	while (ft_strchr(left_part, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (!left_part || *left_part == '\0')
				return (NULL);
			else
				return (left_part);
		}
		buffer[bytes_read] = '\0';
		temp = left_part;
		left_part = ft_strjoin(temp, buffer);
		free(temp);
		if (!left_part)
			return(NULL);
		if (ft_strchr(left_part, '\n') != 0)
			break;
	}
	return (left_part);
}

char *get_next_line(int fd)
{
	static char		*left_part;
	char			*right_part;
	char			buffer[BUFFER_SIZE + 1]; //+1 for the null-terminating.
	char			*line;  //maybe create a final_line variable

	if (fd < 0)
		return NULL;
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	line = read_line(left_part, buffer, fd);
	if (!line)
		return NULL;
	right_part = ft_strchr(line, '\n');
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