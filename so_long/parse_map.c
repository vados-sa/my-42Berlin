#include "so_long.h"

int	check_rectang(char *new_row, t_map *map)
{
	size_t	len;

	len = ft_strlen(new_row);
	if (new_row[len - 1] == '\n')
		len--;
	if (len != map->width)
	{
		free(new_row);
		ft_printf("\nThe map must be rectangle.\n");
		return (0);
	}
	return(len);
}

