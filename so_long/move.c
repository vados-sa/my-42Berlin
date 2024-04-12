/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:14:04 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/12 09:06:03 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_count(t_wrapper *wrapper)
{
	char	*move_count_str;
	char	*label;
	char	*full_message;

	if (wrapper->map->game_end == 0)
	{
		label = "Movement count: ";
		move_count_str = ft_itoa(wrapper->map->move_count);
		full_message = ft_strjoin(label, move_count_str);
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
			wrapper->game->win_ptr, wrapper->game->wall_img, 0, 0);
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
			wrapper->game->win_ptr, wrapper->game->wall_img, 1 * TILE_SIZE, 0);
		mlx_string_put(wrapper->game->mlx_ptr, wrapper->game->win_ptr, 0, \
			TILE_SIZE / 2, 0xFFF4F8, full_message);
		free(move_count_str);
		free(full_message);
	}
}

void	move_up(t_wrapper *wrapper)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y - 1][x] == 'F')
		on_empty_tile(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'C')
	{
		on_object(wrapper, "up");
		if (!wrapper->map->collect_c)
			render_unlocked_exit(wrapper);
	}
	else if (wrapper->map->tiles[y - 1][x] == 'H')
		on_house(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'E' && !wrapper->map->collect_c)
		on_the_exit(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'K')
		on_kenemy(wrapper, "up");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	display_count(wrapper);
}

void	move_left(t_wrapper *wrapper)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x - 1] == 'F')
		on_empty_tile(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'C')
	{
		on_object(wrapper, "left");
		if (!wrapper->map->collect_c)
			render_unlocked_exit(wrapper);
	}
	else if (wrapper->map->tiles[y][x - 1] == 'H')
		on_house(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'E' && !wrapper->map->collect_c)
		on_the_exit(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'K')
		on_kenemy(wrapper, "left");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	display_count(wrapper);
}

void	move_right(t_wrapper *wrapper)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x + 1] == 'F')
		on_empty_tile(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'C')
	{
		on_object(wrapper, "right");
		if (!wrapper->map->collect_c)
			render_unlocked_exit(wrapper);
	}
	else if (wrapper->map->tiles[y][x + 1] == 'H')
		on_house(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'E' && !wrapper->map->collect_c)
		on_the_exit(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'K')
		on_kenemy(wrapper, "right");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	display_count(wrapper);
}

void	move_down(t_wrapper *wrapper)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y + 1][x] == 'F')
		on_empty_tile(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'C')
	{
		on_object(wrapper, "down");
		if (!wrapper->map->collect_c)
			render_unlocked_exit(wrapper);
	}
	else if (wrapper->map->tiles[y + 1][x] == 'H')
		on_house(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'E' && !wrapper->map->collect_c)
		on_the_exit(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'K')
		on_kenemy(wrapper, "down");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	display_count(wrapper);
}
