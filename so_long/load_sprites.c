
#include "so_long.h"

static int	load_collectibles(t_wrapper *wrapper, int width, int height)
{
	wrapper->game->key_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/key.xpm", &width, &height);
	wrapper->game->iphone_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/iphone.xpm", &width, &height);
	wrapper->game->purse_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/purse.xpm", &width, &height);
	wrapper->game->lipstick_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/lipstick.xpm", &width, &height);
	wrapper->game->wallet_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/wallet.xpm", &width, &height);
	wrapper->game->hphones_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/hphones.xpm", &width, &height);
	wrapper->game->skates_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/skates.xpm", &width, &height);
	wrapper->game->dog_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/dog.xpm", &width, &height);
	if (!wrapper->game->key_img || !wrapper->game->iphone_img || \
	!wrapper->game->purse_img || !wrapper->game->lipstick_img || \
	!wrapper->game->wallet_img || !wrapper->game->hphones_img || \
	!wrapper->game->skates_img || !wrapper->game->dog_img)
		return (1);
	return (0);
}

int	load_sprites(t_wrapper *wrapper)
{
	int	width;
	int	height;
	int	collectibles;
	int	bonus;

	width = TILE_SIZE;
	height = TILE_SIZE;
	wrapper->game->floor_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/floor.xpm", &width, &height);
	wrapper->game->wall_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/wall.xpm", &width, &height);
	wrapper->game->house_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/house.xpm", &width, &height);
	wrapper->game->exit_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
		"textures/exit.xpm", &width, &height);
	collectibles = load_collectibles(wrapper, width, height);
	bonus = load_bonus(wrapper, width, height);
	if (!wrapper->game->key_img || !wrapper->game->wall_img || \
		!wrapper->game->house_img || !wrapper->game->exit_img || \
		collectibles || bonus)
	{
		ft_printf("Failed to load one or more sprite(s).\n");
		return (1);
	}
	return (0);
}
