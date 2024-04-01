#include "so_long.h"

/*Update visited tile.*/
static void	mark_tile(int y, int x, t_map *map)
{
	char	original_char;
	char	new_char;

	new_char = '0';
	original_char = map->tiles[y][x];
	if (original_char == 'P')
		new_char = 'S';
	else if (original_char == '0')
		new_char = 'F';
	else if (original_char == 'C')
		new_char = 'O';
	map->tiles[y][x] = new_char;
}

/*Is the exit reachable and all the collectibles colletible?*/
void	final_check(t_map *map)
{
	if (map->found_E == 0)
	{
		ft_printf("\n\nThe exit (E) is not accessible!\n\n");
		ft_printf("Please enter a valid path.\n\n");
		error_exit(map, -2);
	}
	if (map->found_C != map->collect_C)
	{
		ft_printf("\n\nNot all collectibles (C) are accessible!\n\n");
		ft_printf("Please enter a valid path.\n\n");
		error_exit(map, -2);
	}
}

/*Flood Fill algorithm to parse through the map's available path.*/
void	flood_fill(int y, int x, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->tiles[y][x] == 'E')
	{
		map->found_E++;
		return ;
	}
	if (map->tiles[y][x] == '1' || map->tiles[y][x] == 'F' 
		|| map->tiles[y][x] == 'O' || map->tiles[y][x] == 'S')
		return ;
	if (map->tiles[y][x] == 'C')
		map->found_C++;
	mark_tile(y, x, map);
	flood_fill(y, x + 1, map); // Right
	flood_fill(y, x - 1, map); // Left
	flood_fill(y + 1, x, map); // Down
	flood_fill(y - 1, x, map); // Up
}
