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

int	render(t_game *game)
{
	/* if window has been destroyed, we don't want to put the pixel ! */
	if (game->win_ptr)
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, 
			WIN_WIDTH / 2, WIN_HEIGHT / 2, MAG_PIXEL);
	return (0);
}

int	render_background(t_game *game)
{
	int	x;
	int	y;

	if (!game->win_ptr)
		return (1);
	y = 0;
	while (y <= WIN_HEIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, MAG_PIXEL);
			x++;
		}
		y++;
	}
	return (0);
}

static int	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{	
		ft_printf("Failed to initialize mlx.\n");
		return (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
				"Barbie Dream World");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_printf("Failed to create a window.\n");
        return 1;
	}
	return (0);
}

static void	setup_hooks(t_game *game, t_wrapper *wrapper)
{
	mlx_loop_hook(game->mlx_ptr, &render_background, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, wrapper);
	mlx_hook(game->win_ptr, 17, 1L<<17, &close_window, wrapper);
}

int	main(int ac, char *av[])
{
	t_game		game;
	t_map		*map;
	t_wrapper	wrapper;

	check_arguments(ac);
	map = read_map(av[1]);
	if (init_game(&game))
		error_exit(map, -2);
	wrapper.game = &game;
	wrapper.map = map;
	setup_hooks(&game, &wrapper);
	mlx_loop(game.mlx_ptr); // start the game loop
	//cleanup(&wrapper); // seems to be unecessary
	return (0);
}
