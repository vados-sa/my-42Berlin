/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:10 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/16 16:36:36 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>

# define MLX_ERROR 1

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*house_img;
	void	*wall_img;
	void	*floor_img;
	void	*exit_img;

	void	*key_img;
	void	*iphone_img;
	void	*purse_img;
	void	*lipstick_img;
	void	*wallet_img;
	void	*hphones_img;
	void	*skates_img;
	void	*dog_img;

	void	*barbie_left_img;
	void	*barbie_right_img;
	void	*barbie_down_img;
	void	*barbie_up_img;
	void	*win_exit_img;
	void	*unlock_exit_img;
	void	*win_wall_img;

	void	*kenemy_img;
	void	*ken_img;
	void	*mdch_img;
	void	*horse_img;
	void	*kwall_img;
	void	*kfloor_img;
	void	*kar_img;
	void	*sad_barbie_img;
}	t_game;

typedef struct s_map
{
	char	**tiles;
	int		width;
	int		height;
	int		start_p;
	int		exit_e;
	int		collect_c;
	int		found_c;
	int		found_e;
	int		move_count;
	int		x_position;
	int		y_position;
	int		game_over;
	int		game_end;
}	t_map;

typedef struct s_wrapper
{
	t_game	*game;
	t_map	*map;
}	t_wrapper;

/* initial_check.c */
void	check_arguments(int ac);

int		check_fd(const char *filename);
int		check_rectang(char *new_row, t_map *map);

/* create_map.c */
t_map	*read_map(const char *filename, t_wrapper *wrapper);

/* parse_map.c */
void	validate_map(t_map *map, t_wrapper *wrapper);

/* flood_fill.c */
void	flood_fill(int y, int x, t_map *map, t_wrapper *wrapper);
void	final_check(t_map *map, t_wrapper *wrapper);

/*init_game.c*/
int		init_game(t_game *game, t_map *map);
void	distribute_collectibles(t_map *map);
void	find_player_position(t_map *map);

/* load_sprites.c */
int		load_sprites(t_wrapper *wrapper);

/* render_map.c */
int		render_background(t_wrapper *wrapper);

/*hooks.c*/
void	setup_hooks(t_game *game, t_wrapper *wrapper);

/*move.c*/
void	move_up(t_wrapper *wrapper);
void	move_left(t_wrapper *wrapper);
void	move_right(t_wrapper *wrapper);
void	move_down(t_wrapper *wrapper);

/*rerender.c*/
void	put_image(t_wrapper *wrapper, char tile, int y, int x);
void	on_empty_tile(t_wrapper *wrapper, char *direction);
void	on_object(t_wrapper *wrapper, char *direction);
void	on_house(t_wrapper *wrapper, char *direction);
void	on_the_exit(t_wrapper *wrapper, char *direction);

/* cleanup_management.c */
void	error_exit(t_wrapper *wrapper, int fd);
void	cleanup(t_wrapper *wrapper);
void	clean_game(t_game *game);
void	free_map(t_map *map);

/*free_images.c*/
void	free_collectibles_1(t_game *game);
void	free_collectibles_2(t_game *game);
void	free_images(t_game *game);
void	free_extra_sprites(t_game *game);

/*bonus*/
/*load_bonus_sprites.c*/
int		load_bonus(t_wrapper *wrapper, int width, int height);
/*free_bonus.c*/
void	free_bonus(t_game *game);
void	free_enemy(t_game *game);
void	free_enemy2(t_game *game);
void	free_barbie(t_game *game);
void	free_extra_sprites(t_game *game);
/*kenemy.c*/
void	put_bonus_image(t_wrapper *wrapper, char tile, int y, int x);
void	render_game_over(t_wrapper *wrapper);
void	on_kenemy(t_wrapper *wrapper, char *direction);
/*sprite_anim*/
void	render_unlocked_exit(t_wrapper *wrapper);
void	render_game_win(t_wrapper *wrapper);
void	put_barbie_img(t_wrapper *wrapper, int y, int x, char *direction);

#endif