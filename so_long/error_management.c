#include "so_long.h".

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

void	error_exit(t_map *map, int fd)
{
	char *temp;

	free_map(map);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(temp);
	}
	ft_printf("\nError!\n\n");
	exit (1);
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
