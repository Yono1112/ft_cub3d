#include "cub3d.h"

void	error(char *str)
{
	write(STDERR_FILENO, ERROR_PREFIX, ft_strlen(ERROR_PREFIX));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	exit_error(char *str, t_map *mapdata, char **map)
{
	if (mapdata)
		free_data(mapdata, map);
	write(STDERR_FILENO, ERROR_PREFIX, ft_strlen(ERROR_PREFIX));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
