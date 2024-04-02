/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:59:13 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/02 19:59:14 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_game(t_game *game)
{
	free_extra_sprites(game);
	free_images(game);
	free_collectibles_1(game);
	free_collectibles_2(game);
	free_bonus(game);
	free_bonus2(game);
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

void	cleanup(t_wrapper *wrapper)
{
	clean_game(wrapper->game);
	free_map(wrapper->map);
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
	exit (0);
}

void	error_exit(t_map *map, int fd)
{
	char	*temp;

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
	if (fd == -1)
		ft_printf("Please insert a valid map.\n\n");
	ft_printf("\nError!\n\n");
	exit (1);
}
