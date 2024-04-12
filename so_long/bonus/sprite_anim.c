/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:39:40 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/12 09:15:55 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_unlocked_exit(t_wrapper *wrapper)
{
	int	y;
	int	x;

	y = 1;
	while (y < wrapper->map->height)
	{
		x = 1;
		while (x < wrapper->map->width)
		{
			if (wrapper->map->tiles[y][x] == 'E')
				mlx_put_image_to_window(wrapper->game->mlx_ptr, \
		wrapper->game->win_ptr, wrapper->game->unlock_exit_img, \
		x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_game_win(t_wrapper *wrapper)
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
				mlx_put_image_to_window(wrapper->game->mlx_ptr, \
				wrapper->game->win_ptr, wrapper->game->win_wall_img, \
				x * TILE_SIZE, y * TILE_SIZE);
			if (wrapper->map->tiles[y][x] == 'K')
				mlx_put_image_to_window(wrapper->game->mlx_ptr, \
				wrapper->game->win_ptr, wrapper->game->floor_img, \
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	put_barbie_img(t_wrapper *wrapper, int y, int x, char *direction)
{
	void	*img;

	img = NULL;
	if (ft_strncmp(direction, "up", 3) == 0)
		img = wrapper->game->barbie_up_img;
	else if (ft_strncmp(direction, "down", 5) == 0)
		img = wrapper->game->barbie_down_img;
	else if (ft_strncmp(direction, "left", 5) == 0)
		img = wrapper->game->barbie_left_img;
	else if (ft_strncmp(direction, "right", 6) == 0)
		img = wrapper->game->barbie_right_img;
	if (img)
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
		wrapper->game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}
