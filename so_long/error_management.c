#include "so_long.h"

static void	free_collectibles_1(t_game *game)
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

static void	free_collectibles_2(t_game *game)
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

void	clean_game(t_game *game)
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
	free_collectibles_1(game);
	free_collectibles_2(game);
	free_bonus(game);
	free_bonus2(game);
}

void	cleanup(t_wrapper *wrapper)
{
	clean_game(wrapper->game);
	free_map(wrapper->map);
	if (wrapper->game->win_ptr != NULL)
	{
		mlx_destroy_window(wrapper->game->mlx_ptr, wrapper->game->win_ptr);
		wrapper->game->win_ptr = NULL;
	}
	if (wrapper->game->mlx_ptr != NULL)
	{
		mlx_destroy_display(wrapper->game->mlx_ptr);
		free(wrapper->game->mlx_ptr);
		wrapper->game->mlx_ptr = NULL;
	}
	exit (0);
}

void	error_exit(t_map *map, int fd)
{
	char	*temp;

	free_map(map);
	if (fd >= 0)
	{
		while (1)
		{
			temp = get_next_line(fd);
			if (!temp)
				break ;
			free(temp);
		}
	}
	if (fd == -1)
		ft_printf("Please insert a valid map.\n\n");
	ft_printf("\nError!\n\n");
	exit (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->tiles[i++]);
	free(map->tiles);
	free(map);
	return ;
}
