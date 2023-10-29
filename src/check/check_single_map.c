#include "cub3d.h"

bool	is_blankline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return true;
	while (line[i])
	{
		if (ft_isprint(line[i]))
			return false;
		i++;
	}
	return true;
}

void	check_single_map(char **map, int i, t_map *mapdata)
{
	while (map[i])
	{
		if (is_blankline(map[i]) && !is_blankline(map[i + 1]))
			exit_error(TOO_MANY_MAPS, mapdata, map);
		i++;
	}
}

