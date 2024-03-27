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

int	render_background(t_wrapper *wrapper)
{
	int		x;
	int		y;
	//void	*img;

	y = 0;
	while (y < wrapper->map->height)
	{
		x = 0;
		while (x < wrapper->map->width)
		{
			mlx_put_image_to_window(wrapper->game->mlx_ptr, \
			wrapper->game->win_ptr, wrapper->game->floor_img, \
			x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
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
				map->height * TILE_SIZE, "Barbie Dream World");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_printf("Failed to create 'Barbie Dream World'.\n");
        return 1;
	}
	return (0);
}

int	load_sprites(t_wrapper *wrapper)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	wrapper->game->floor_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/Floor.xpm", &width, &height);
	if (!wrapper->game->floor_img)
	{
		ft_printf("Failed to load Floor sprite.\n");
		return (1);
	}
	return (0);
}

static void	setup_hooks(t_game *game, t_wrapper *wrapper)
{
	mlx_loop_hook(game->mlx_ptr, &render_background, wrapper);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, wrapper);
	mlx_hook(game->win_ptr, 17, 1L<<17, &close_window, wrapper);
}

int	main(int ac, char *av[]) // some of those functions I might just need to pass wrapper!
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
	setup_hooks(&game, &wrapper);
	mlx_loop(game.mlx_ptr); // start the game loop
	//cleanup(&wrapper); // seems to be unecessary
	return (0);
}
