#include "so_long.h"
void	free_map(t_map *map);

void cleanup(t_wrapper *wrapper)
{
    if (wrapper->data->win_ptr != NULL)
    {
        mlx_destroy_window(wrapper->data->mlx_ptr, wrapper->data->win_ptr);
        wrapper->data->win_ptr = NULL;
    }
    if (wrapper->data->mlx_ptr != NULL)
    {
        mlx_destroy_display(wrapper->data->mlx_ptr);
        free(wrapper->data->mlx_ptr);
        wrapper->data->mlx_ptr = NULL;
    }
	free_map(wrapper->map);
    exit (0);
}

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

int	render(t_data *data)
{
	/* if window has been destroyed, we don't want to put the pixel ! */
	if (data->win_ptr)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
			WIN_WIDTH / 2, WIN_HEIGHT / 2, MAG_PIXEL);
	return (0);
}

int	render_background(t_data *data)
{
	int	x;
	int	y;

	if (!data->win_ptr)
		return (1);
	y = 0;
	while (y <= WIN_HEIGHT)
	{
		x = 0;
		while (x <= WIN_WIDTH)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, MAG_PIXEL);
			x++;
		}
		y++;
	}
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->tiles[i++]);
	free(map->tiles);
	free(map);
	return ;
}

int	main(void)
{
	t_data		data;
	t_map		*map;
	t_wrapper	wrapper;

	map = read_map("map.ber");
	wrapper.data = &data;
	wrapper.map = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Game");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	/* Setup hooks */ 
	mlx_loop_hook(data.mlx_ptr, &render_background, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &wrapper);
	mlx_hook(data.win_ptr, 17, 1L<<17, close_window, &wrapper);
	mlx_loop(data.mlx_ptr);
	//cleanup(&wrapper); // seems to be unecessary
	return (0);
}
