/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:50:53 by vados-sa          #+#    #+#             */
/*   Updated: 2024/01/26 16:06:42 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(const char *str);
char			*set_remaining(char *line);
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
char	*set_remaining(char *line)
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
	static char		*remain[MAX_FD];
	char			*line;
	char			*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > MAX_FD)
	{
		free (remain[fd]);
		free (buffer);
		remain[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	line = read_line(remain[fd], buffer, fd);
	free (buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remain[fd] = set_remaining(line); 
	return (line);
}

/* 
# include <fcntl.h>
# include <stdio.h>
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("get_next_line_bonus.h", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line1 != NULL)
			printf("File Descriptor 1: %s", line1);
		if (line2 != NULL)
			printf("File Descriptor 2: %s", line2);
		if (line1 == NULL && line2 == NULL)
			break ;
	}
	close(fd1);
	close(fd2);
} */