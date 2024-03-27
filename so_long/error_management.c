#include "so_long.h"

void cleanup(t_wrapper *wrapper)
{
    if (wrapper->game->win_ptr != NULL)
    {
        mlx_destroy_window(wrapper->game->mlx_ptr, wrapper->game->win_ptr);
        wrapper->game->win_ptr = NULL;
    }
    if (wrapper->game->mlx_ptr != NULL)
    {
        mlx_destroy_display(wrapper->game->mlx_ptr);
        free(wrapper->game->mlx_ptr);
        wrapper->game->mlx_ptr = NULL;
    }
	free_map(wrapper->map);
    exit (0);
}

void	error_exit(t_map *map, int fd)
{
	char *temp;

	free_map(map);
	if (fd >= 0)
	{
		while (1)
		{
			temp = get_next_line(fd);
			if (!temp)
				break ;
			free(temp);
		}
	}
	if (fd == - 1)
		ft_printf("Please insert a valid map.\n\n");
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
