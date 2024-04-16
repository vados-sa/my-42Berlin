/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:59:13 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/16 14:00:16 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_mlx(t_wrapper *wrapper)
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
}

void	error_exit(t_wrapper *wrapper, int fd)
{
	char	*temp;

	free_map(wrapper->map);
	clean_game(wrapper->game);
	if (fd >= 0)
	{
		while (1)
		{
			temp = get_next_line(fd);
			if (!temp)
				break ;
			free(temp);
		}
		close(fd);
	}
	if (fd == -1)
		ft_printf("Please insert a valid map.\n\n");
	free_mlx(wrapper);
	ft_printf("\nError!\n\n");
	exit (1);
}

void	clean_game(t_game *game)
{
	free_images(game);
	free_collectibles_1(game);
	free_collectibles_2(game);
	free_bonus(game);
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
	free_mlx(wrapper);
	exit (0);
}
