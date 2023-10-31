/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/31 13:44:43 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	skip_space(char **map, int *i, t_map *mapdata)
{
	int	j;

	while (map[*i])
	{
		j = 0;
		while (!ft_isprint(map[*i][j]) && map[*i][j])
			j++;
		if (ft_isprint(map[*i][j]))
			break ;
		(*i)++;
	}
	if (!map[*i])
		exit_error(NOT_ENOUGH_ARGUMENT_ERROR, mapdata, map);
}

char**	creat_new_map(char **map, int i)
{
	int	j;
	int	stock;
	char	**newmap;

	stock = i;
	while (map[stock])
		stock++;
	newmap = (char **)malloc(sizeof(char *) * (stock - i + 1));
	if (!newmap)
		exit_error(MALLOC_ERROR, NULL, NULL);
	newmap[stock - i] = NULL;
	stock = i;
	i = 0;
	while (map[i + stock])
	{
		j = 0;
		while (map[i + stock][j])
		{
			if (map[i + stock][j] == ' ')
				map[i + stock][j] = '1';
			else if(map[i + stock][j] == '2')
				map[i + stock][j] = '0';
			j++;
		}
		newmap[i] = ft_strdup(map[i + stock]);
		if (!newmap[i])
			exit_error(MALLOC_ERROR, NULL, NULL);
		i++;
	}
	return (newmap);
}

void	check_mapfile(char **map, t_map *mapdata)
{
	int	i;

	i = check_texture(map, mapdata);
	check_single_map(map, i, mapdata);
	check_map(map, i);
	check_mapcontents(map, i, mapdata);
	check_mapcollect(map, i, mapdata);
	check_floor_ceiling(map, mapdata);
	check_readable_texture(map, mapdata);
	mapdata->map = creat_new_map(map, i);
}
