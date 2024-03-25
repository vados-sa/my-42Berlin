#include "so_long.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map)); // map is not being freed
	if (!map)
	{
		ft_printf("\nError while initializing the map!\n\n");
		exit (1);
	}
	map->tiles = NULL;
	map->height = 0;
	map->width = 0;
	map->start_P = 0;
	map->exit_E = 0;
	map->collect_C = 0;
	return (map);
}

void	set_map_width(t_map *map, char *row)
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
		return (-1);//error_exit(map, fd);
	temp = malloc(sizeof(char *) * (map->height + 1)); // Allocate space for one more pointer in tiles.
	if (!temp)
		return (-1);
	i = 0;
	while (i < map->height) // Copy existing pointers from map->tiles to temp.
	{
		temp[i] = map->tiles[i];
		i++;
	} // Add new_row to temp and update map->tiles.
	temp[map->height] = new_row; 
	free(map->tiles); // Free old tiles array.
	map->tiles = temp; // Update tiles to new array.
	map->height++;
	return (0);
}

t_map	*read_map(const char *filename)
{
	int		fd;
	char	*row;
	t_map	*map;

	fd = check_fd(filename);
	map = init_map(); //in case of error, init_map handles it.
	while (1)
	{
		row = get_next_line(fd);		
		if (!row)
			break ;
		if(map->height == 0)
			set_map_width(map, row);
		if (update_map(map, row) == -1)
			error_exit(map, fd);
		//free (row);
	}
	close(fd);
	validate_map(map);
	return (map);
}
