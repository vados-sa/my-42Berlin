/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:55:03 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/16 16:36:25 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Update visited tile.*/
static void	mark_tile(int y, int x, t_map *map)
{
	char	original_char;
	char	new_char;

	new_char = '0';
	original_char = map->tiles[y][x];
	if (original_char == 'P')
		new_char = 'S';
	else if (original_char == '0')
		new_char = 'F';
	else if (original_char == 'C')
		new_char = 'O';
	map->tiles[y][x] = new_char;
}

/*Is the exit reachable and all the collectibles colletible?*/
void	final_check(t_map *map, t_wrapper *wrapper)
{
	if (map->found_e == 0)
	{
		ft_printf("\n\nThe exit (E) is not accessible!\n\n");
		ft_printf("Please enter a valid path.\n\n");
		error_exit(wrapper, -2);
	}
	if (map->found_c != map->collect_c)
	{
		ft_printf("\n\nNot all collectibles (C) are accessible!\n\n");
		ft_printf("Please enter a valid path.\n\n");
		error_exit(wrapper, -2);
	}
}

/*Flood Fill algorithm to parse through the map's available path.*/
void	flood_fill(int y, int x, t_map *map, t_wrapper *wrapper)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->tiles[y][x] == 'E')
	{
		map->found_e++;
		return ;
	}
	if (map->tiles[y][x] == '1' || map->tiles[y][x] == 'F' 
		|| map->tiles[y][x] == 'O' || map->tiles[y][x] == 'S'
		|| map->tiles[y][x] == 'K')
		return ;
	if (map->tiles[y][x] == 'C')
		map->found_c++;
	mark_tile(y, x, map);
	flood_fill(y, x + 1, map, wrapper);
	flood_fill(y, x - 1, map, wrapper);
	flood_fill(y + 1, x, map, wrapper);
	flood_fill(y - 1, x, map, wrapper);
}
