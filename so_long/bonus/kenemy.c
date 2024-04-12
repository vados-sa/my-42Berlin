/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kenemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:43:24 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/12 09:04:51 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_bonus_image(t_wrapper *wrapper, char tile, int y, int x)
{
	void	*img;

	img = NULL;
	if (tile == '1')
		img = wrapper->game->kwall_img;
	else if (tile == 'F')
		img = wrapper->game->kfloor_img;
	else if (tile == 'E')
		img = wrapper->game->kar_img;
	else if (tile == 'K')
		img = wrapper->game->ken_img;
	else if (tile == 'B')
		img = wrapper->game->sad_barbie_img;
	else if (tile == 'H')
		img = wrapper->game->mdch_img;
	else if (tile == 'C')
		img = wrapper->game->horse_img;
	if (img)
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
		wrapper->game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_game_over(t_wrapper *wrapper)
{
	int	y;
	int	x;

	y = 0;
	while (y < wrapper->map->height)
	{
		x = 0;
		while (x < wrapper->map->width)
		{
			if (wrapper->map->tiles[y][x] == '1')
				put_bonus_image(wrapper, '1', y, x);
			if (wrapper->map->tiles[y][x] == 'F')
				put_bonus_image(wrapper, 'F', y, x);
			if (wrapper->map->tiles[y][x] == 'E')
				put_bonus_image(wrapper, 'E', y, x);
			if (wrapper->map->tiles[y][x] == 'K')
				put_bonus_image(wrapper, 'K', y, x);
			if (wrapper->map->tiles[y][x] == 'H')
				put_bonus_image(wrapper, 'H', y, x);
			if (wrapper->map->tiles[y][x] == 'C')
				put_bonus_image(wrapper, 'C', y, x);
			x++;
		}
		y++;
	}
}

void	on_kenemy(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	put_bonus_image(wrapper, 'B', y, x);
	if (ft_strncmp(direction, "up", 3) == 0)
		wrapper->map->y_position -= 1;
	else if (ft_strncmp(direction, "down", 5) == 0)
		wrapper->map->y_position += 1;
	else if (ft_strncmp(direction, "left", 5) == 0)
		wrapper->map->x_position -= 1;
	else if (ft_strncmp(direction, "right", 6) == 0)
		wrapper->map->x_position += 1;
	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	mlx_put_image_to_window(wrapper->game->mlx_ptr, wrapper->game->win_ptr, \
		wrapper->game->ken_img, x * TILE_SIZE, y * TILE_SIZE);
	render_game_over(wrapper);
	wrapper->map->game_end = 1;
	wrapper->map->game_over = 1;
}
