/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:10 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/01 16:05:04 by vados-sa         ###   ########.fr       */
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

//# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>

# define MLX_ERROR 1

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	//int		width;     // Width of the sprite - AM I USING IT?
    //int		height;    // Height of the sprite - AM I USING IT?
	void	*barbie_img;
	void	*house_img;
    void	*wall_img;
	void	*floor_img;
    void	*exit_img;
	void	*exit2_img;
	/*collectibles*/
    void	*key_img;
	void	*iphone_img;
	void	*purse_img;
	void	*lipstick_img;
	void	*wallet_img;
	void	*hphones_img;
	void	*skates_img;
	void	*dog_img;
	/*kenemy*/
	void	*kenemy_img;
	void	*ken_img;
	void	*mdch_img;
	void	*horse_img;
	void	*kenwall_img;
	void	*kenough_img;
	//void	*kencar_img;
	//void	*downbarbie_img;
}	t_game;

typedef struct s_map
{
	char			**tiles;
	int				width;
	int				height;
	int				start_P;
	int				exit_E;
	int				collect_C;
	int				found_C;
	int				found_E;
}	t_map;

typedef struct s_wrapper
{
	t_game	*game;
	t_map	*map;
} t_wrapper;

/* initial_check.c */
void	check_arguments(int ac);
int		check_fd(const char *filename);
int		check_rectang(char *new_row, t_map *map);

/* create_map.c */
t_map	*read_map(const char *filename);

/* parse_map.c */
void	validate_map(t_map *map);

/* flood_fill.c */
void	flood_fill(int y, int x, t_map *map);
void	final_check(t_map *map);

/* load_sprites.c */
int	load_sprites(t_wrapper *wrapper);

/* render_map.c */
int	render_background(t_wrapper *wrapper);

/* error_management.c */
void 	cleanup(t_wrapper *wrapper);
void	error_exit(t_map *map, int fd);
void	free_map(t_map *map);

/*bonus.c*/
int	load_bonus(t_wrapper *wrapper, int width, int height);
void	free_bonus(t_game *game);
void	free_bonus2(t_game *game);

#endif