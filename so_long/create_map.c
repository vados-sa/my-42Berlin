/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:40:39 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/16 16:30:49 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("\nError while initializing the map!\n\n");
		exit (1);
	}
	map->tiles = NULL;
	map->height = 0;
	map->width = 0;
	map->start_p = 0;
	map->exit_e = 0;
	map->collect_c = 0;
	map->found_c = 0;
	map->found_e = 0;
	map->move_count = 0;
	map->x_position = 0;
	map->y_position = 0;
	map->game_over = 0;
	map->game_end = 0;
	return (map);
}

static void	set_map_width(t_map *map, char *row)
{
	size_t	len;

	len = ft_strlen(row);
	if (row[len - 1] == '\n')
		len--;
	map->width = len;
}

static int	update_map(t_map *map, char *new_row)
{
	int		i;
	char	**temp;
	size_t	len;

	len = check_rectang(new_row, map);
	if (!len)
		return (-1);
	temp = malloc(sizeof(char *) * (map->height + 1));
	if (!temp)
		return (-1);
	i = 0;
	while (i < map->height)
	{
		temp[i] = map->tiles[i];
		i++;
	}
	temp[map->height] = new_row; 
	free (map->tiles);
	map->tiles = temp;
	map->height++;
	return (0);
}

t_map	*read_map(const char *filename, t_wrapper *wrapper)
{
	int		fd;
	char	*row;
	t_map	*map;

	fd = check_fd(filename);
	map = init_map();
	while (1)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		if (map->height == 0)
			set_map_width(map, row);
		if (update_map(map, row) == -1)
			error_exit(wrapper, fd);
	}
	close(fd);
	validate_map(map, wrapper);
	return (map);
}
