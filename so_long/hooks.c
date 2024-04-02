#include "so_long.h"

static int	close_window(t_wrapper *wrapper);
static int	handle_keypress(int keysym, t_wrapper *wrapper);
void	put_image(t_wrapper *wrapper, char tile, int y, int x);
void    on_empty_tile(t_wrapper *wrapper, char *direction);
void	on_object(t_wrapper *wrapper, char *direction);
void	on_house(t_wrapper *wrapper, char *direction);
void    move_up(t_wrapper *wrapper);
void    move_left(t_wrapper *wrapper);
void    move_right(t_wrapper *wrapper);
void    move_down(t_wrapper *wrapper);

void	setup_hooks(t_game *game, t_wrapper *wrapper)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, wrapper);
	mlx_hook(game->win_ptr, 17, 1L << 17, &close_window, wrapper);
}

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

void	put_image(t_wrapper *wrapper, char tile, int y, int x)
{
	void	*img;

	img = NULL;
	if (tile == 'H')
		img = wrapper->game->house_img;
	else if (tile == 'F')
		img = wrapper->game->floor_img;
	else if (tile == 'B')  // maybe some sprite animation here for Barbie!!
		img = wrapper->game->barbie_img;
	else if (tile == 'W')
		img = wrapper->game->exit2_img;
	if (img)
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
		wrapper->game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

/*move to game_render.c*/
void    on_empty_tile(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x] == 'H')
		put_image(wrapper, 'H', y, x);
	else
	{
		put_image(wrapper, 'F', y, x);
		wrapper->map->tiles[y][x] = 'F';
	}
	if (ft_strncmp(direction, "up", 3) == 0)
		wrapper->map->y_position -= 1;
	else if (ft_strncmp(direction, "down", 5) == 0)
		wrapper->map->y_position += 1;
	else if (ft_strncmp(direction, "left", 5) == 0)
		wrapper->map->x_position -= 1;
	else if (ft_strncmp(direction, "right", 6) == 0)
		wrapper->map->x_position += 1;
	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	wrapper->map->tiles[y][x] = 'B';
	put_image(wrapper, 'B', y, x);
}

void	on_object(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x] == 'H')
		put_image(wrapper, 'H', y, x);
	else
	{
		put_image(wrapper, 'F', y, x);
		wrapper->map->tiles[y][x] = 'F';
	}
	if (ft_strncmp(direction, "up", 3) == 0)
		wrapper->map->y_position -= 1;
	else if (ft_strncmp(direction, "down", 5) == 0)
		wrapper->map->y_position += 1;
	else if (ft_strncmp(direction, "left", 5) == 0)
		wrapper->map->x_position -= 1;
	else if (ft_strncmp(direction, "right", 6) == 0)
		wrapper->map->x_position += 1;
	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	wrapper->map->tiles[y][x] = 'B';
	put_image(wrapper, 'B', y, x);
	wrapper->map->collect_C--;
}

void	on_house(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	put_image(wrapper, 'F', y, x);
	wrapper->map->tiles[y][x] = 'F';
	if (ft_strncmp(direction, "up", 3) == 0)
		wrapper->map->y_position -= 1;
	else if (ft_strncmp(direction, "down", 5) == 0)
		wrapper->map->y_position += 1;
	else if (ft_strncmp(direction, "left", 5) == 0)
		wrapper->map->x_position -= 1;
	else if (ft_strncmp(direction, "right", 6) == 0)
		wrapper->map->x_position += 1;
	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	wrapper->map->tiles[y][x] = 'H';
	put_image(wrapper, 'H', y, x);
}

void	on_the_exit(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	put_image(wrapper, 'F', y, x);
	wrapper->map->tiles[y][x] = 'F';
	if (ft_strncmp(direction, "up", 3) == 0)
		wrapper->map->y_position -= 1;
	else if (ft_strncmp(direction, "down", 5) == 0)
		wrapper->map->y_position += 1;
	else if (ft_strncmp(direction, "left", 5) == 0)
		wrapper->map->x_position -= 1;
	else if (ft_strncmp(direction, "right", 6) == 0)
		wrapper->map->x_position += 1;
	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	wrapper->map->tiles[y][x] = 'W'; // for Won
	put_image(wrapper, 'W', y, x);
	wrapper->map->game_over = 1;
}

/*move to bonus*/
void	put_bonus_image(t_wrapper *wrapper, char tile, int y, int x)
{
	void	*img;

	img = NULL;
	if (tile == '1')
		img = wrapper->game->kenwall_img;
	else if (tile == 'F')
		img = wrapper->game->kenough_img;
	//else if (tile == 'E')
		//img = wrapper->game->kencar_img;
	//else if (tile == 'B')
		//img = wrapper->game->sadbarbie_img;
	else if (tile == 'H')
		img = wrapper->game->mdch_img;
	else if (tile == 'C')
		img = wrapper->game->horse_img;
	if (img)
		mlx_put_image_to_window(wrapper->game->mlx_ptr, \
		wrapper->game->win_ptr, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_game_over(t_wrapper *wrapper)
{
	int	y;
	int x;

	y = 0;
	while (y < wrapper->map->height)
	{
		x = 0;
		while (x < wrapper->map->width)
		{
			if (wrapper->map->tiles[y][x] == '1')
				put_bonus_image(wrapper, '1', y, x);
			if (wrapper->map->tiles[y][x] == 'F') // need to check for '0' (zeros) on the map too!!
				put_bonus_image(wrapper, 'F', y, x);
			//if (wrapper->map->tiles[y][x] == 'E')
				//put_bonus_image(wrapper, 'E', y, x);
			//if (wrapper->map->tiles[y][x] == 'B')
				//put_bonus_image(wrapper, 'B', y, x);
			if (wrapper->map->tiles[y][x] == 'H')
				put_bonus_image(wrapper, 'H', y, x);
			if (wrapper->map->tiles[y][x] == 'C')
				put_bonus_image(wrapper, 'C', y, x);
			x++;
		}
		y++;
	}
}

void	on_kenemy(t_wrapper *wrapper, char *direction)
{
	int	y;
	int	x;

	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	//put image of sad barbie
	if (ft_strncmp(direction, "up", 3) == 0)
		wrapper->map->y_position -= 1;
	else if (ft_strncmp(direction, "down", 5) == 0)
		wrapper->map->y_position += 1;
	else if (ft_strncmp(direction, "left", 5) == 0)
		wrapper->map->x_position -= 1;
	else if (ft_strncmp(direction, "right", 6) == 0)
		wrapper->map->x_position += 1;
	y = wrapper->map->y_position;
	x = wrapper->map->x_position;
	mlx_put_image_to_window(wrapper->game->mlx_ptr, wrapper->game->win_ptr, \
		wrapper->game->ken_img, x * TILE_SIZE, y * TILE_SIZE);
	render_game_over(wrapper);
	mlx_string_put(wrapper->game->mlx_ptr, wrapper->game->win_ptr, TILE_SIZE, \
		TILE_SIZE / 2, 0xFFF4F8, "Barbie lost!");
	wrapper->map->game_over = 1;
}

/*move those to moves.c*/
void    move_up(t_wrapper *wrapper)
{
	int y;
	int x;

	y = wrapper->map->y_position;
    x = wrapper->map->x_position;
	if (wrapper->map->tiles[y - 1][x] == 'F')
		on_empty_tile(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'C')
		on_object(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'H')
		on_house(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'E' && !wrapper->map->collect_C)
		on_the_exit(wrapper, "up");
	else if (wrapper->map->tiles[y - 1][x] == 'K')
		on_kenemy(wrapper, "up");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	mlx_string_put(wrapper->game->mlx_ptr, wrapper->game->win_ptr, 0, \
		TILE_SIZE / 2, 0xFFF4F8, "Movement count:");
}

void    move_left(t_wrapper *wrapper)
{
	int y;
	int x;

	y = wrapper->map->y_position;
    x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x - 1] == 'F')
		on_empty_tile(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'C')
		on_object(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'H')
		on_house(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'E' && !wrapper->map->collect_C)
		on_the_exit(wrapper, "left");
	else if (wrapper->map->tiles[y][x - 1] == 'K')
		on_kenemy(wrapper, "left");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	mlx_string_put(wrapper->game->mlx_ptr, wrapper->game->win_ptr, 0, \
		TILE_SIZE / 2, 0xFFF4F8, "Movement count:");
}

void    move_right(t_wrapper *wrapper)
{
	int y;
	int x;

	y = wrapper->map->y_position;
    x = wrapper->map->x_position;
	if (wrapper->map->tiles[y][x + 1] == 'F')
		on_empty_tile(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'C')
		on_object(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'H')
		on_house(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'E' && !wrapper->map->collect_C)
		on_the_exit(wrapper, "right");
	else if (wrapper->map->tiles[y][x + 1] == 'K')
		on_kenemy(wrapper, "right");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	mlx_string_put(wrapper->game->mlx_ptr, wrapper->game->win_ptr, 0, \
		TILE_SIZE / 2, 0xFFF4F8, "Movement count:");
}

void    move_down(t_wrapper *wrapper)
{
	int y;
	int x;

	y = wrapper->map->y_position;
    x = wrapper->map->x_position;
	if (wrapper->map->tiles[y + 1][x] == 'F')
		on_empty_tile(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'C')
		on_object(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'H')
		on_house(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'E' && !wrapper->map->collect_C)
		on_the_exit(wrapper, "down");
	else if (wrapper->map->tiles[y + 1][x] == 'K')
		on_kenemy(wrapper, "down");
	else
		return ;
	wrapper->map->move_count++;
	ft_printf("\nNumber of movements: %d\n\n", wrapper->map->move_count);
	mlx_string_put(wrapper->game->mlx_ptr, wrapper->game->win_ptr, 0, \
		TILE_SIZE / 2, 0xFFF4F8, "Movement count:");
}
