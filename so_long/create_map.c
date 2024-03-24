#include "so_long.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map)); // map is not being freed
	if (!map)
		return (NULL);
	map->tiles = NULL;
	map->height = 0;
	map->width = 0;
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

static void	error_exit(t_map *map, int fd) // maybe put in another file
{
	int	i;
	char *temp;

	i = 0;
	while (i < map->height)
	{
		free(map->tiles[i++]);
		//i++;
	}
	free(map->tiles);
	free(map);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(temp);
	}
	ft_printf("\nError!\n\n");
	exit (1);
}

t_map	*read_map(const char *filename)
{
	int		fd;
	char	*row;
	t_map	*map;

	fd = check_fd(filename);
	map = init_map();
	if (!map)
		return (NULL);
	while (1)
	{
		row = get_next_line(fd);
		if (row) // take out - 5 extra lines.
    	{
    	    printf("%s", row);
    	    fflush(stdout);
    	}
		if (!row)
			break ;
		if(map->height == 0)
			set_map_width(map, row);
		if (update_map(map, row) == -1)
			error_exit(map, fd);
		//free (row);
	}
	close(fd);
	//validate_map(map);
	return (map);
}
