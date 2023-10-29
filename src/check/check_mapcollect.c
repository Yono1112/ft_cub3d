#include "cub3d.h"
void	check_hole(char **map, int i, int j, int border, t_map *mapdata)
{
	if ((!map[i + 1] && map[i][j] == '0') || map[i][j] == ' ' || map[i][j] == '\0' || (map[i][j] == '\0' && j == 0 ))
		exit_error(HOLE_MAP_ERROR, mapdata, map);
	if (j < 0 || i < border || !map[i] || map[i][j] == '\0' || map[i][j] == '1' || map[i][j] == '2')//すでに移動した箇所を2に置き換えている。"D"などにすべき
		 return ;
	if (map[i][j] == '0')
		map[i][j] = '2';
	check_hole(map, i + 1, j, border, mapdata);
	check_hole(map, i - 1, j, border, mapdata);
	check_hole(map, i, j + 1, border, mapdata);
	check_hole(map, i, j - 1, border, mapdata);
}

void	check_mapcollect(char **map, int i, t_map *mapdata)
{
	int	j;
	int	border;

	skip_space(map, &i, mapdata);
	border = i;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
				break ;
			j++;
		}
		if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
			break ;
		i++;
	}
	check_hole(map, i, j, border, mapdata);
}

