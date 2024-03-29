#include "so_long.h"

int	handle_keypress(int keysym, t_wrapper *wrapper)
{
	if (keysym == XK_Escape)
		cleanup(wrapper);
	return (0);
}
int	close_window(t_wrapper *wrapper)
{
	cleanup(wrapper);
	return (0);
}

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
        return 1;
	}
	return (0);
}

static void	setup_hooks(t_game *game, t_wrapper *wrapper)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, wrapper);
	mlx_hook(game->win_ptr, 17, 1L<<17, &close_window, wrapper);
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
	setup_hooks(&game, &wrapper);
	mlx_loop(game.mlx_ptr); // start the game loop
	//cleanup(&wrapper); // seems to be unecessary
	return (0);
}
