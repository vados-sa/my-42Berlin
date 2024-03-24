#include "so_long.h"

void	check_arguments(int ac)
{
	if (ac != 2)
	{
		ft_printf("\nIncorrect number of arguments!\n\n");
		ft_printf("Usage:\n\t./so_long ./maps/map.ber*\n\n");
		ft_printf("\t*'map.ber' should be replaced with map file name.\n\n");
		exit (1);
	}
}

int	check_fd(const char *filename)
{
	int		fd;
	size_t	len;

	len = ft_strlen(filename);
	if(len <= 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
	{
		ft_printf("\nError!\n\nInvalid file type: \"%s\".\n", filename);
		ft_printf("The file has to end with a .ber extention.\n\n");
		exit (1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\nError!\n\nFile does not exist or cannot be opened: ");
        ft_printf("\"%s\".\n\n", filename);
		exit (1);
	}
	return (fd);
}
