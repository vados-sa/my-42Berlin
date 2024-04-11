/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:59:03 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/11 12:01:11 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->floor_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->floor_img);
		game->floor_img = NULL;
	}
	if (game->wall_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->wall_img);
		game->wall_img = NULL;
	}
	if (game->house_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->house_img);
		game->house_img = NULL;
	}
	if (game->exit_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->exit_img);
		game->exit_img = NULL;
	}
}

void	free_collectibles_1(t_game *game)
{
	if (game->key_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->key_img);
		game->key_img = NULL;
	}
	if (game->iphone_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->iphone_img);
		game->iphone_img = NULL;
	}
	if (game->purse_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->purse_img);
		game->purse_img = NULL;
	}
	if (game->lipstick_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->lipstick_img);
		game->lipstick_img = NULL;
	}
}

void	free_collectibles_2(t_game *game)
{
	if (game->wallet_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->wallet_img);
		game->wallet_img = NULL;
	}
	if (game->hphones_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->hphones_img);
		game->hphones_img = NULL;
	}
	if (game->skates_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->skates_img);
		game->skates_img = NULL;
	}
	if (game->dog_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->dog_img);
		game->dog_img = NULL;
	}
}
