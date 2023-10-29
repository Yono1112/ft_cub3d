#include "cub3d.h"
char*	change_newline_to_null(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	printf("%s\n",str);
	return (str);
}

char	*check_direction(char *line, char *dir, char **map, t_map *mapdata)
{
	int j = 0;

	while (!ft_isalpha(line[j]))
		j++;
	if (ft_strncmp(line + j, dir, ft_strlen(dir))) //方向キー
		exit_error(TEXTURE_ERROR, mapdata, map);
	j += ft_strlen(dir);
	if (ft_strlen(dir) == 1)
	{
		while (line[j] && !ft_isdigit(line[j]))
			j++;
	}
	else
	{
		while (line[j] && (!ft_isprint(line[j]) || line[j] == ' '))
			j++;
	}
	return change_newline_to_null(ft_strdup(line + j));//テクスチャー名の後のスペースを除けていない
}

int	check_texture(char **map, t_map *mapdata)
{
	int	i;

	i = 0;
	skip_space(map, &i, mapdata);
	mapdata->no = check_direction(map[i], "NO", map, mapdata);
	i++;
	skip_space(map, &i, mapdata);
	mapdata->so = check_direction(map[i], "SO", map, mapdata);
	i++;
	skip_space(map, &i, mapdata);
	mapdata->we = check_direction(map[i], "WE", map, mapdata);
	i++;
	skip_space(map, &i, mapdata);
	mapdata->ea = check_direction(map[i], "EA", map, mapdata);
	i++;
	skip_space(map, &i, mapdata);
	mapdata->floor = check_direction(map[i], "F", map, mapdata);
	i++;
	skip_space(map, &i, mapdata);
	mapdata->ceiling = check_direction(map[i], "C", map, mapdata);
//------------------------------------------------------------
//	printf("no = %s\n", mapdata->no);
//	printf("so = %s\n", mapdata->so);
//	printf("ea = %s\n", mapdata->ea);
//	printf("we = %s\n", mapdata->we);
//	printf("floor = %s\n", mapdata->floor);
//	printf("ceiling = %s\n", mapdata->ceiling);
//------------------------------------------------------------
	i++;
	skip_space(map, &i, mapdata);
	return i;
}

