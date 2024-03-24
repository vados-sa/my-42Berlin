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

/*Is the map surrounded by walls?*/
static void    check_walls(t_map *map)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(x < map->width)
    {
        if (map->tiles[0][x] != '1' || map->tiles[map->height - 1][x] != '1')
        {
            ft_printf("\nMap not enclosed by walls!\n");
            free_map(map);
            exit (1);
        }
        x++;
    }
    while(y < map->height)
    {
        if (map->tiles[y][0] != '1' || map->tiles[y][map->width - 1] != '1')
        {
            ft_printf("\nMap not enclosed by walls!");
            free_map(map);
            exit (1);
        }
        y++;
    }
}

void validate_map(t_map *map)
{
    if (map->height > 0 && map->width > 0) // map is not empty
    {
        check_walls(map);
        //does it have the required elements?
        // - 1 exit (no duplicates! -> error message)
        // - at least 1 collectible
        // - 1 starting position (no duplicates! -> error message)
    }
    else
    {
        ft_printf("\nThe map is empty or not properly initialized!\n");
        ft_printf("Please insert a valid map.\n\n");
        exit (1);
    }
}
