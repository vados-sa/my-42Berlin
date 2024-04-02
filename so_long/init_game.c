/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:47:47 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/02 19:47:48 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, t_map *map)
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
