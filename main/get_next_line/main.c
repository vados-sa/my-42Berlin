/* 
# include "get_next_line.h" 
# include <fcntl.h>
# include <stdio.h>
int	main(void)
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