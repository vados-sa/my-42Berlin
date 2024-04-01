#include "so_long.h"

int	load_bonus(t_wrapper *wrapper, int width, int height)
{
	wrapper->game->kenemy_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kenemy.xpm", &width, &height);
	wrapper->game->ken_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/ken.xpm", &width, &height);
	wrapper->game->mdch_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/mdch.xpm", &width, &height);
	wrapper->game->horse_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/horse.xpm", &width, &height);
	wrapper->game->kenwall_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kenwall.xpm", &width, &height);
	wrapper->game->kenough_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kenough.xpm", &width, &height);
	/* wrapper->game->kencar_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kencar.xpm", &width, &height);
	wrapper->game->downbarbie_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/downbarbie.xpm", &width, &height); */
	if (!wrapper->game->kenemy_img || !wrapper->game->ken_img || \
		 !wrapper->game->mdch_img || !wrapper->game->horse_img || \
		 !wrapper->game->kenwall_img || !wrapper->game->kenemy_img /*|| \
		 !wrapper->game->kencar_img || !wrapper->game->downbarbie_img*/)
		return (1);
	return (0);
}

void	free_bonus(t_game *game)
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

void	free_bonus2(t_game *game)
{
	if (game->kenwall_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kenwall_img);
		game->kenwall_img = NULL;
	}
	if (game->kenough_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kenough_img);
		game->kenough_img = NULL;
	}
	/* if (game->kencar_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->kencar_img);
		game->kencar_img = NULL;
	}
	if (game->downbarbie_img)
	{
		mlx_destroy_image(game->mlx_ptr, downbarbie_img);
		game->downbarbie_img = NULL;
	} */
}