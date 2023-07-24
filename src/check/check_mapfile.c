/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/07/24 20:40:55 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	*check_south(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "SO", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_east(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "EA", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_west(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "WE", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_north(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

int	skip_space(char **map, int i)
{
	int	j;

	while (map[i])
	{
		j = 0;
		while (!ft_isalpha(map[i][j]) && map[i][j])
			j++;
		if (ft_isalpha(map[i][j]))
			break ;
		i++;
	}
	return i;
}

char	*check_ceiling(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "C", 1))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_floor(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "F", 1))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

void	check_texture(char **map, t_map *mapdata)
{
	int	i;
	int	j;

	i = 0;
	i = skip_space(map, i);
	mapdata->no = check_north(map[i]);
	i++;
	i = skip_space(map, i);
	mapdata->so = check_south(map[i]);
	i++;
	i = skip_space(map, i);
	mapdata->ea = check_east(map[i]);
	i++;
	i = skip_space(map, i);
	mapdata->we = check_west(map[i]);
	i++;
	if (!map[i])
		error(5);
	i = skip_space(map, i);
	mapdata->floor = check_floor(map[i]);
	i++;
	if (!map[i])
		error(5);
	i = skip_space(map, i);
	mapdata->ceiling = check_ceiling(map[i]);
}

void	check_mapfile(char **map, t_map *mapdata)
{
	check_texture(map, mapdata);
	check_map(map, mapdata);
}
