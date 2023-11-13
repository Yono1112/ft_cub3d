/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:57:59 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/13 10:49:02 by rnaka            ###   ########.fr       */
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
	return (str);
}

void	move_path(char *line, int dir_num, t_map *mapdata)
{
	if (dir_num == 1 && !mapdata->no)
		mapdata->no = line;
	if (dir_num == 2 && !mapdata->so)
		mapdata->so = line;
	if (dir_num == 3 && !mapdata->ea)
		mapdata->ea = line;
	if (dir_num == 4 && !mapdata->we)
		mapdata->we = line;
	if (dir_num == 5 && !mapdata->floor)
		mapdata->floor = line;
	if (dir_num == 6 && !mapdata->ceiling)
		mapdata->ceiling = line;
}

bool	is_null(int dir_num, t_map *mapdata)
{
	if (dir_num == 1 && !mapdata->no)
		return (true);
	if (dir_num == 2 && !mapdata->so)
		return (true);
	if (dir_num == 3 && !mapdata->ea)
		return (true);
	if (dir_num == 4 && !mapdata->we)
		return (true);
	if (dir_num == 5 && !mapdata->floor)
		return (true);
	if (dir_num == 6 && !mapdata->ceiling)
		return (true);
	return (false);
}

int	is_texture_trigger(char *trigger)
{
	char	*dir;

	dir = "NO ";
	if (!ft_strncmp(trigger, dir, ft_strlen(dir)))
		return (1);
	dir = "SO ";
	if (!ft_strncmp(trigger, dir, ft_strlen(dir)))
		return (2);
	dir = "EA ";
	if (!ft_strncmp(trigger, dir, ft_strlen(dir)))
		return (3);
	dir = "WE ";
	if (!ft_strncmp(trigger, dir, ft_strlen(dir)))
		return (4);
	dir = "F ";
	if (!ft_strncmp(trigger, dir, ft_strlen(dir)))
		return (5);
	dir = "C ";
	if (!ft_strncmp(trigger, dir, ft_strlen(dir)))
		return (6);
	return (0);
}

void	check_direction(char *line, char **map, t_map *mapdata)
{
	int	j;
	int	dir_num;

	j = 0;
	while (!ft_isprint(line[j]) || line[j] == ' ')
		j++;
	dir_num = is_texture_trigger(line + j);
	if (!dir_num)
		exit_error(TEXTURE_ERROR, mapdata, map);
	if (dir_num <= 5)
		j += 3;
	else
		j += 2;
	while (line[j] && (!ft_isprint(line[j]) || line[j] == ' '))
		j++;
	if (!is_null(dir_num, mapdata))
		exit_error(TEXTURE_ERROR, mapdata, map);
	move_path(change_newline_to_null(ft_strdup(line + j)), dir_num, mapdata);
}
