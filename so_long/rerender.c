/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:17:28 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/12 09:22:03 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_wrapper *wrapper, char tile, int y, int x)
{
	void	*img;

	img = NULL;
	if (tile == 'H')
		img = wrapper->game->house_img;
	else if (tile == 'F')
		img = wrapper->game->floor_img;
	else if (tile == 'W')
		img = wrapper->game->win_exit_img;
	if (img)
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
		wrapper->game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

/*move to game_render.c*/
void	on_empty_tile(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x] == 'H')
		put_image(wrapper, 'H', y, x);
	else
	{
		put_image(wrapper, 'F', y, x);
		wrapper->map->tiles[y][x] = 'F';
	}
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
	wrapper->map->tiles[y][x] = 'B';
	put_barbie_img(wrapper, y, x, direction);
}

void	on_object(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x] == 'H')
		put_image(wrapper, 'H', y, x);
	else
	{
		put_image(wrapper, 'F', y, x);
		wrapper->map->tiles[y][x] = 'F';
	}
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
	wrapper->map->tiles[y][x] = 'B';
	put_barbie_img(wrapper, y, x, direction);
	wrapper->map->collect_c--;
}

void	on_house(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	put_image(wrapper, 'F', y, x);
	wrapper->map->tiles[y][x] = 'F';
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
	wrapper->map->tiles[y][x] = 'H';
	put_image(wrapper, 'H', y, x);
}

void	on_the_exit(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	put_image(wrapper, 'F', y, x);
	wrapper->map->tiles[y][x] = 'F';
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
	wrapper->map->tiles[y][x] = 'W';
	put_image(wrapper, 'W', y, x);
	render_game_win(wrapper);
	wrapper->map->game_end = 1;
	wrapper->map->game_over = 1;
}
