/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:45:16 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/02 03:36:12 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*change_newline_to_null(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	printf("%s\n", str);
	return (str);
}

char	*check_direction(char *line, char *dir, char **map, t_map *mapdata)
{
	int	j;

	j = 0;
	while (!ft_isprint(line[j]) || line[j] == ' ')
		j++;
	if (ft_strncmp(line + j, dir, ft_strlen(dir)))
		exit_error(TEXTURE_ERROR, mapdata, map);
	j += ft_strlen(dir);
	while (line[j] && (!ft_isprint(line[j]) || line[j] == ' '))
		j++;
	return (change_newline_to_null(ft_strdup(line + j)));
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
	i++;
	skip_space(map, &i, mapdata);
	return (i);
}
