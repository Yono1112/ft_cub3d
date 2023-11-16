/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapcollect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:39:58 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/16 15:26:36 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_hole(char **map, int i, int j, int deadline)
{
	int	result;

	if ((!map[i + 1] && map[i][j] == '0') || map[i][j] == ' '
		|| map[i][j] == '\0' || (map[i][j] == '\0' && j == 0))
		return (1);
	if (deadline > 1000)
		return (2);
	if (j < 0 || i < 0 || !map[i] || map[i][j] == '\0'
		|| map[i][j] == '1' || map[i][j] == '2')
		return (0);
	if (map[i][j] == '0')
		map[i][j] = '2';
	result = check_hole(map, i + 1, j, ++deadline);
	if (result)
		return (result);
	result = check_hole(map, i - 1, j, ++deadline);
	if (result)
		return (result);
	result = check_hole(map, i, j + 1, ++deadline);
	if (result)
		return (result);
	result = check_hole(map, i, j - 1, ++deadline);
	if (result)
		return (result);
	return (--deadline, 0);
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
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'W' || map[i][j] == 'S' )
				break ;
			j++;
		}
		if (map[i][j] == 'N' || map[i][j] == 'E'
			|| map[i][j] == 'W' || map[i][j] == 'S' )
			break ;
		i++;
	}
	border = check_hole(map + border, i - border, j, 0);
	if (border == 1)
		exit_error(HOLE_MAP_ERROR, mapdata, map);
	if (border == 2)
		exit_error(HUGE_MAP_ERROR, mapdata, map);
}
