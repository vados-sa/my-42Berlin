/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:24:56 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/10 14:24:57 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_wrapper *wrapper);
static int	handle_keypress(int keysym, t_wrapper *wrapper);

static int	close_window(t_wrapper *wrapper)
{
	cleanup(wrapper);
	return (0);
}

static int	handle_keypress(int keysym, t_wrapper *wrapper)
{
	if (keysym == XK_Escape)
		cleanup(wrapper);
	if (wrapper->map->game_over)
		return (0);
	else if (keysym == XK_Up || keysym == XK_w)
	{
		move_up(wrapper);
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		move_down(wrapper);
	}
	else if (keysym == XK_Left || keysym == XK_a)
	{
		move_left(wrapper);
	}
	else if (keysym == XK_Right || keysym == XK_d)
	{
		move_right(wrapper);
	}
	return (0);
}

void	setup_hooks(t_game *game, t_wrapper *wrapper)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, wrapper);
	mlx_hook(game->win_ptr, 17, 1L << 17, &close_window, wrapper);
}
