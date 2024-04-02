#include "so_long.h"

static int	init_game(t_game *game, t_map *map)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Failed to initialize mlx.\n");
		return (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, map->width * TILE_SIZE, \
				map->height * TILE_SIZE, "Barbie Dream World <3");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_printf("Failed to create 'Barbie Dream World <3'.\n");
		return (1);
	}
	return (0);
}

void	distribute_collectibles(t_map *map)
{
	int	type;
	int	total;
	int	x;
	int	y;

	type = 0;
	total = 8;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->tiles[y][x] == 'O')
			{
				map->tiles[y][x] = 'a' + type;
				type = (type + 1) % total;
			}
			x++;
		}
		y++;
	}
}

/* void print_map(t_map *map)
{
    int y;
	int	x;

    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            ft_putchar_fd(map->tiles[y][x], 1); // Assuming ft_putchar_fd prints a single character to the given file descriptor, in this case, stdout.
        }
        ft_putchar_fd('\n', 1);
    }
} */

void	find_player_position(t_map *map)
{
	int	x;
	int	y;

	x = 1;
	while (x < map->width)
	{
		y = 1;
		while (y < map->height)
		{
			if (map->tiles[y][x] == 'S' || map->tiles[y][x] == 'B')
			{
				map->x_position = x;
				map->y_position = y;
				if (map->tiles[y][x] == 'S')
					map->tiles[y][x] = 'H';
				return ;
			}
			y++;
		}
		x++;
	}
}

int	main(int ac, char *av[])
{
	t_game		game;
	t_map		*map;
	t_wrapper	wrapper;

	check_arguments(ac);
	map = read_map(av[1]);
	wrapper.game = &game;
	wrapper.map = map;
	if (init_game(&game, map))
		error_exit(map, -2);
	if (load_sprites(&wrapper))
		error_exit(map, -2);
	distribute_collectibles(map);
	render_background(&wrapper);
	find_player_position(map);
	setup_hooks(&game, &wrapper);
	mlx_loop(game.mlx_ptr);
	return (0);
}
