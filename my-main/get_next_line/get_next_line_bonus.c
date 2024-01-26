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