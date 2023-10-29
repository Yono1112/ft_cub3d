#include "cub3d.h"

void	check_mapcontents(char **map, int i, t_map *mapdata)
{
	int	count_news;
	int	j;

	count_news = 0;
	skip_space(map, &i, mapdata);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' )
				exit_error(MAP_ARGUMENT_ERROR, mapdata, map);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
			{
				if (count_news)
					exit_error(MAP_ARGUMENT_ERROR, mapdata, map);
				count_news++;
			}
			j++;
		}
		i++;
	}
	if (!count_news)
		exit_error(NUM_ARGUMENT_ERROR, mapdata, map);
}

