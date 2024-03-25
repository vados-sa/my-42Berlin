#include "so_long.h"

/*Update visited tile.*/
static void	mark_tile(int y, int x, t_map *map)
{
	char	original_char;
	char	new_char;

	original_char = map->tiles[y][x];
	if (original_char == 'P')
		new_char = 'S';
	else if (original_char == '0')
		new_char = 'F';
	else if (original_char == 'C')
		new_char = 'O';
	else if (original_char == 'E')
		new_char = 'D';
	map->tiles[y][x] = new_char;
}

/*Is the exit reachable and all the collectibles colletible?*/
static void	final_check(int num_exit, int num_collectibles, t_map *map)
{
	if (num_exit == 0)
	{
		ft_printf("\n\nThe exit (E) is not accessible!\n\n");
		ft_printf("Please enter a valid path.\n\n");
		error_exit(map, -2);
	}
	if (num_collectibles != map->collect_C)
	{
		ft_printf("\n\nNot all collectibles (C) are accessible!\n\n");
		ft_printf("Please enter a valid path.\n\n");
		error_exit(map, -2);
	}
}

/*Flood Fill algorithm to parse through the map's available path.*/
void	flood_fill(int y, int x, t_map *map)
{
	static int	num_exit;
	static int	num_collect;

	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->tiles[y][x] == '1' || map->tiles[y][x] == 'F' 
		|| map->tiles[y][x] == 'O' || map->tiles[y][x] == 'S' 
		|| map->tiles[y][x] == 'D')
		return ;
	if (map->tiles[y][x] == 'E')
		num_exit++;
	if (map->tiles[y][x] == 'C')
		num_collect++;
	mark_tile(y, x, map);
	flood_fill(y, x + 1, map); // Right
    flood_fill(y, x - 1, map); // Left
    flood_fill(y + 1, x, map); // Down
    flood_fill(y - 1, x, map); // Up
	final_check(num_exit, num_collect, map);
}
