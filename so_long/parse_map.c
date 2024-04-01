#include "so_long.h"

static void	check_walls(t_map *map);
static int	check_elements(t_map *map);
static void	invalid_char(t_map *map, int x, int y);
static void	valid_path(t_map *map);

/*Is the map surrounded by walls?*/
static void	check_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->width)
	{
		if (map->tiles[0][x] != '1' || map->tiles[map->height - 1][x] != '1')
		{
			ft_printf("\nMap not enclosed by walls!\n");
			free_map(map);
			exit (1);
		}
		x++;
	}
	while (y < map->height)
	{
		if (map->tiles[y][0] != '1' || map->tiles[y][map->width - 1] != '1')
		{
			ft_printf("\n\nMap not enclosed by walls!\n\n");
			free_map(map);
			exit (1);
		}
		y++;
	}
}

/*Does the map has the required elements?*/
static int	check_elements(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	while (x < map->width)
	{
		y = 1;
		while (y < map->height)
		{
			if (map->tiles[y][x] == 'P')
				map->start_P++;
			else if (map->tiles[y][x] == 'E')
				map->exit_E++;
			else if (map->tiles[y][x] == 'C')
				map->collect_C++;
			else if (map->tiles[y][x] != '0' && map->tiles[y][x] != '1'
						&& map->tiles[y][x] != 'K')
			invalid_char(map, x, y);
			y++;
		}
		x++;
	}
	if (map->start_P != 1 || map->exit_E != 1 || map->collect_C < 1)
		return (1);
	return (0);
}

/*Are the characters valid?*/
static void	invalid_char(t_map *map, int x, int y)
{
	ft_printf("\n\n%c is an invalid character!\n\n", map->tiles[x][y]);
	error_exit(map, -1);
}

/*Is the path valid on the map?*/
static void	valid_path(t_map *map)
{
	int	y;
	int	x;
	int	found_p;

	y = 1;
	found_p = 0;
	while (y < map->height && !found_p)
	{
		x = 1;
		while (x < map->width)
		{
			if (map->tiles[y][x] == 'P')
			{
				found_p = 1;
				break ;
			}
			x++;
		}
		y++;
	}
	flood_fill(y - 1, x, map);
	final_check(map);
}

void	validate_map(t_map *map)
{
	if (map->height > 0 && map->width > 0)
	{
		check_walls(map);
		if (check_elements(map) == 1)
		{
			if (map->start_P == 0)
				ft_printf("\nStarting Position (P) not found!\n\n");
			if (map->exit_E == 0)
				ft_printf("\nExit (E) not found!\n\n");
			if (map->start_P > 1 || map->exit_E > 1)
			{
				ft_printf("\nNo duplicates allowed!\nOnly one Starting pos");
				ft_printf("ition (P) and only one Exit (E) are accepted!\n\n");
			}
			if (map->collect_C < 1)
				ft_printf("\nAt least one Collectible (C) is required!\n\n");
			error_exit(map, -1);
		}
	}
	else
	{
		ft_printf("\nThe map is empty or not properly initialized!\n\n");
		error_exit(map, -1);
	}
	valid_path(map);
}
