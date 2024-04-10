/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:40:03 by vados-sa          #+#    #+#             */
/*   Updated: 2024/04/10 11:35:09 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int ac)
{
	if (ac != 2)
	{
		ft_printf("\nIncorrect number of arguments!\n\n");
		ft_printf("Usage:\n\t./so_long ./maps/map.ber*\n\n");
		ft_printf("\t*'map.ber' should be replaced with map file name.\n\n");
		exit (1);
	}
}

int	check_fd(const char *filename)
{
	int		fd;
	int		len;

	len = ft_strlen(filename);
	if (len <= 4 || ft_strncmp(&filename[len - 4], ".ber", 4))
	{
		ft_printf("\nError!\n\nInvalid file type: \"%s\".\n", filename);
		ft_printf("The file has to end with a .ber extention.\n\n");
		exit (1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\nError!\n\nFile does not exist or cannot be opened: ");
		ft_printf("\"%s\".\n\n", filename);
		exit (1);
	}
	return (fd);
}

/*Is the map rectangle?*/
int	check_rectang(char *new_row, t_map *map)
{
	int	len;

	len = ft_strlen(new_row);
	if (new_row[len - 1] == '\n')
		len--;
	if (len != map->width)
	{
		free(new_row);
		ft_printf("\nThe map must be rectangle!\n");
		return (0);
	}
	return (len);
}
