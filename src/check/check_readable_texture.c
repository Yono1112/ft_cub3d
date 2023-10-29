#include "cub3d.h"

void	check_readable_texture(char **map, t_map *mapdata)
{
	int	fd;

	fd = open(mapdata->no,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
	fd = open(mapdata->so,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
	fd = open(mapdata->ea,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
	fd = open(mapdata->we,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
}

