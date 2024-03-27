/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:10 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/27 13:32:18 by vados-sa         ###   ########.fr       */
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

# define WIN_WIDTH 640
# define WIN_HEIGHT 320

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;     // Width of the sprite
    int		height;    // Height of the sprite
	void	*barbie_img; // Pointer to Barbie sprite image
    void	*object_img; // Pointer to collectible sprite image
    void	*wall_img; // Pointer to wall sprite image
    void	*exit_img; // Pointer to exit sprite image
	void	*floor_img;
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

/*initial_check.c*/
void	check_arguments(int ac);
int		check_fd(const char *filename);
int		check_rectang(char *new_row, t_map *map);

/*create_map.c*/
t_map	*read_map(const char *filename);

/*parse_map.c*/
void	validate_map(t_map *map);

/*flood_fill.c*/
void	flood_fill(int y, unsigned int x, t_map *map);
void	final_check(t_map *map);

/*error_management.c*/
void 	cleanup(t_wrapper *wrapper);
void	error_exit(t_map *map, int fd);
void	free_map(t_map *map);

#endif