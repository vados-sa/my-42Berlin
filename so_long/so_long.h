/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:10 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/23 17:14:09 by vados-sa         ###   ########.fr       */
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

# define RED_PIXEL 0xFF0000
# define MAG_PIXEL 0xb2007f

# define WIN_WIDTH 600
# define WIN_HEIGHT 300

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_map
{
	char	**tiles;
	int		width;
	int		height;
}	t_map;

typedef struct s_wrapper
{
	t_data	*data;
	t_map	*map;
} t_wrapper;

t_map	*read_map(const char *filename);

#endif