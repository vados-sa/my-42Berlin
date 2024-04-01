#include "so_long.h"

static void	collectibles_back_to_c(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->tiles[y][x] == 'a' || map->tiles[y][x] == 'b' ||
				map->tiles[y][x] == 'c' || map->tiles[y][x] == 'd' || 
				map->tiles[y][x] == 'e' || map->tiles[y][x] == 'f' || 
				map->tiles[y][x] == 'g' || map->tiles[y][x] == 'h')
			{
				map->tiles[y][x] = 'C';
			}
			x++;
		}
		y++;
	}
}

static void	*get_collect_sprite(t_wrapper *wrapper, char tile)
{
	if (tile == 'a')
		return (wrapper->game->key_img);
	if (tile == 'b')
		return (wrapper->game->iphone_img);
	if (tile == 'c')
		return (wrapper->game->purse_img);
	if (tile == 'd')
		return (wrapper->game->lipstick_img);
	if (tile == 'e')
		return (wrapper->game->wallet_img);
	if (tile == 'f')
		return (wrapper->game->hphones_img);
	if (tile == 'g')
		return (wrapper->game->skates_img);
	if (tile == 'h')
		return (wrapper->game->dog_img);
	return (NULL);
}

static void	*get_sprite(t_wrapper *wrapper, int x, int y)
{
	char	tile;

	tile = wrapper->map->tiles[y][x];
	if (tile == '1')
		return (wrapper->game->wall_img);
	if (tile == 'S') // Player start position
		return (wrapper->game->house_img);
	if (tile == 'E') // Exit
		return (wrapper->game->exit_img);
	if (tile == 'K') // Kenemy
		return (wrapper->game->kenemy_img);
	else
		return (get_collect_sprite(wrapper, tile));
	return (NULL);
}

static void	render_sprites(t_wrapper *wrapper)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < wrapper->map->height)
	{
		x = 0;
		while (x < wrapper->map->width)
		{
			img = get_sprite(wrapper, x, y);
			if (img)
				mlx_put_image_to_window(wrapper->game->mlx_ptr, \
				wrapper->game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
			img = NULL;
			x++;
		}
		y++;
	}
}

int	render_background(t_wrapper *wrapper)
{
	int		x;
	int		y;

	y = 0;
	while (y < wrapper->map->height)
	{
		x = 0;
		while (x < wrapper->map->width)
		{
			mlx_put_image_to_window(wrapper->game->mlx_ptr, \
			wrapper->game->win_ptr, wrapper->game->floor_img, \
			x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	render_sprites(wrapper);
	collectibles_back_to_c(wrapper->map);
	return (0);
}
