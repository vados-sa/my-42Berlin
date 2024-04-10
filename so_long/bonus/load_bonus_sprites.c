/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:02 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/10 12:27:24 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	load_extra_sprites(t_wrapper *wrapper, int width, int height);
static int	load_kenemy(t_wrapper *wrapper, int width, int height);

/*Loads the images used for sprite animation.*/
static int	load_extra_sprites(t_wrapper *wrapper, int width, int height)
{
	wrapper->game->barbie_left_img = mlx_xpm_file_to_image(wrapper->game->\
		mlx_ptr, "textures/barbie_left.xpm", &width, &height);
	wrapper->game->barbie_right_img = mlx_xpm_file_to_image(wrapper->game->\
		mlx_ptr, "textures/barbie_right.xpm", &width, &height);
	wrapper->game->barbie_down_img = mlx_xpm_file_to_image(wrapper->game->\
		mlx_ptr, "textures/barbie_down.xpm", &width, &height);
	wrapper->game->barbie_up_img = mlx_xpm_file_to_image(wrapper->game->\
		mlx_ptr, "textures/barbie_up.xpm", &width, &height);
	wrapper->game->win_exit_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/win_exit.xpm", &width, &height);
	wrapper->game->unlock_exit_img = mlx_xpm_file_to_image(wrapper->game->\
		mlx_ptr, "textures/unlock_exit.xpm", &width, &height);
	wrapper->game->win_wall_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/win_wall.xpm", &width, &height);
	if (!wrapper->game->barbie_left_img || !wrapper->game->barbie_right_img || \
		!wrapper->game->barbie_down_img || !wrapper->game->barbie_up_img || \
		!wrapper->game->win_exit_img || !wrapper->game->unlock_exit_img || \
		!wrapper->game->win_wall_img)
		return (1);
	return (0);
}

/*Loads the images for the implementing an enemy.*/
static int	load_kenemy(t_wrapper *wrapper, int width, int height)
{
	wrapper->game->kenemy_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kenemy.xpm", &width, &height);
	wrapper->game->ken_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/ken.xpm", &width, &height);
	wrapper->game->mdch_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/mdch.xpm", &width, &height);
	wrapper->game->horse_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/horse.xpm", &width, &height);
	wrapper->game->kwall_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kwall.xpm", &width, &height);
	wrapper->game->kfloor_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kfloor.xpm", &width, &height);
	wrapper->game->kar_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kar.xpm", &width, &height);
	wrapper->game->sad_barbie_img = mlx_xpm_file_to_image(wrapper->game->\
		mlx_ptr, "textures/sad_barbie.xpm", &width, &height);
	if (!wrapper->game->kenemy_img || !wrapper->game->ken_img || \
		!wrapper->game->mdch_img || !wrapper->game->horse_img || \
		!wrapper->game->kwall_img || !wrapper->game->kfloor_img || \
		!wrapper->game->kar_img || !wrapper->game->sad_barbie_img)
		return (1);
	return (0);
}

int	load_bonus(t_wrapper *wrapper, int width, int height)
{
	int	kenemy_imgs;
	int	extra_sprites;

	kenemy_imgs = load_kenemy(wrapper, width, height);
	extra_sprites = load_extra_sprites(wrapper, width, height);
	if (kenemy_imgs || extra_sprites)
		return (1);
	return (0);
}
