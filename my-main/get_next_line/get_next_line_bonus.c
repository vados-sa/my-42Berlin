/* int	main(void)
{
	int		fd3;
	int		fd4;
	char	*line1;
	char	*line2;

	fd3 = open("text1.txt", O_RDONLY);
	fd4 = open("get_next_line_bonus.h", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd3);
		line2 = get_next_line(fd4);
		if (line1 != NULL)
			printf("File Descriptor 3: %s", line1);
		if (line2 != NULL)
			printf("File Descriptor 4: %s", line2);
		if (line1 == NULL && line2 == NULL)
			break ;
	}
	close(fd3);
	close(fd4);
} */