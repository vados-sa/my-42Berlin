/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:44:27 by vados-sa          #+#    #+#             */
/*   Updated: 2024/01/26 11:59:38 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str);
static char		*set_remaining(char *line);
char			*concat_strings(char *remain, char *buffer);
char			*read_line(char *remain, char *buffer, int fd);
char			*get_next_line(int fd);

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

/* This function extracts the part of the string following the newline
and modifies the original string to end at the newline.
If no additional text follows the newline, or if no newline is found,
the function returns NULL.*/
static char	*set_remaining(char *line)
{
	char	*remain;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	remain = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remain == '\0')
	{
		free (remain);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (remain);
}

/* This funtion is responsible for reading from a fd 
and filling the buffer with the content read.
It also handles concatenating any previously remaining content. */
char	*read_line(char *remain, char *buffer, int fd)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (remain);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (remain == NULL)
			remain = ft_strdup("");
		temp = remain;
		remain = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (remain);
}

char	*get_next_line(int fd)
{
	static char		*remain;
	char			*line;
	char			*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (remain);
		free (buffer);
		remain = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	line = read_line(remain, buffer, fd);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remain = set_remaining(line); 
	return (line);
}

/* int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	if (fd == -1)
    	return 1;
	i = 1;
	while (i < 100)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line %d: %s", i, line);
		if (line == NULL)
			break;
		i++;
		free(line);
	}
	close(fd);
	return (0);
} */

/*PREVIOUS VERSION
#include "get_next_line.h"

size_t	ft_strlen(const char *str);
char	*set_line(char *line);
char	*concat_strings(char *left_part, char *buffer);
char	*read_line(char *left_part, char *buffer, int fd);
char	*get_next_line(int fd);

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

char	*set_line(char *line)
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
			return (NULL);
		}
	}
	else
	{
		final_line = ft_strdup(line);
		if (!final_line)
		{
			free (line);
			return (NULL);
		}
	}
	free (line);
	return (final_line);
}

char	*concat_strings(char *left_part, char *buffer)
{
	char	*temp;

	temp = left_part;
	left_part = ft_strjoin(temp, buffer);
	if (!left_part)
		return (NULL);
	free(temp);
	return (left_part);
}


//This funtion reads the line until it finds \n or \0,
//and concatenate the strings.
char	*read_line(char *left_part, char *buffer, int fd)
{
	int		bytes_read;

	while (ft_strchr(left_part, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && (!left_part || *left_part == '\0'))
			return (NULL);
		else if (bytes_read <= 0)
			return (left_part);
		buffer[bytes_read] = '\0';
		if (left_part == NULL)
		{
			left_part = ft_strdup(buffer);
			if (!left_part)
				return (NULL);
		}
		else
		{
			left_part = concat_strings(left_part, buffer);
			if (!left_part)
				return (NULL);
		}
	}
	return (left_part);
}

char	*get_next_line(int fd)
{
	static char		*left_part;
	char			*right_part;
	char			*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	line = read_line(left_part, buffer, fd);
	free (buffer);
	if (!line)
		return (NULL);
	right_part = ft_strchr(line, '\n');
	if (right_part != NULL)
	{
		right_part++;
		left_part = ft_substr(line, right_part - line, ft_strlen(right_part));
		if (!left_part)
			return (NULL);
	}
	line = set_line(line); 
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("get_next_line.h", O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line %d: %s", i, line);
		if (line == NULL)
			break;
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
*/
