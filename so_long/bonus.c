#include "so_long.h"

int	load_bonus(t_wrapper *wrapper, int width, int height)
{
	wrapper->game->kenemy_img = mlx_xpm_file_to_image(wrapper->game->mlx_ptr, \
	"textures/kenemy.xpm", &width, &height);
	if (!wrapper->game->kenemy_img)
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
}
/* void bonus_main(void)
{

} */