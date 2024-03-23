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

static int	update_map(t_map *map, char *new_row)
{
	int		i;
	char	**temp;

	temp = malloc(sizeof(char *) * (map->height + 1)); // Allocate space for one more pointer in tiles.
	if (!temp)
		return (-1); // final temp is npt being freed!!
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

static void	error_exit(t_map *map) //remember to free the outer map->tiles
{                              // array itself after freeing each string within it.
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->tiles[i++]);
		//i++;
	}
	free(map->tiles);
	free(map);
	ft_printf("Error!");
	exit (1);
}

t_map	*read_map(const char *filename)
{
	int		fd;
	char	*row;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = init_map();
	if (!map)
		return (NULL);
	while (1)
	{
		row = get_next_line(fd);
		if (row) // remember to take this out.
    	{
    	    printf("%s", row);
    	    fflush(stdout); // Manually flush stdout to ensure immediate output.
    	}
		if (!row) // what about when get_next_line failures?
			break ;
		if(map->height == 0)
			map->width = ft_strlen(row);
		if (update_map(map, row) == -1)
			error_exit(map);
		//free (row);
	}
	close(fd);
	return (map);
}
/* 
int	main(void)
{
	t_map *map;

	map = read_map("map.ber");
	return (0);
} */
