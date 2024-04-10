/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:39:41 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/10 14:40:45 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_enemy(t_game *game)
{
	if (game->kenemy_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kenemy_img);
		game->kenemy_img = NULL;
	}
	if (game->ken_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->ken_img);
		game->ken_img = NULL;
	}
	if (game->mdch_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->mdch_img);
		game->mdch_img = NULL;
	}
	if (game->horse_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->horse_img);
		game->horse_img = NULL;
	}
}

void	free_enemy2(t_game *game)
{
	if (game->kwall_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kwall_img);
		game->kwall_img = NULL;
	}
	if (game->kfloor_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kfloor_img);
		game->kfloor_img = NULL;
	}
	if (game->kar_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kar_img);
		game->kar_img = NULL;
	}
	if (game->sad_barbie_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->sad_barbie_img);
		game->sad_barbie_img = NULL;
	}
}

void	free_barbie(t_game *game)
{
	if (game->barbie_left_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->barbie_left_img);
		game->barbie_left_img = NULL;
	}
	if (game->barbie_right_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->barbie_right_img);
		game->barbie_right_img = NULL;
	}
	if (game->barbie_down_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->barbie_down_img);
		game->barbie_down_img = NULL;
	}
	if (game->barbie_up_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->barbie_up_img);
		game->barbie_up_img = NULL;
	}
}

void	free_extra_sprites(t_game *game)
{
	if (game->win_exit_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->win_exit_img);
		game->win_exit_img = NULL;
	}
	if (game->unlock_exit_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->unlock_exit_img);
		game->unlock_exit_img = NULL;
	}
	if (game->win_wall_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->win_wall_img);
		game->win_wall_img = NULL;
	}
}

void	free_bonus(t_game *game)
{
	free_enemy(game);
	free_enemy2(game);
	free_barbie(game);
	free_extra_sprites(game);
}
