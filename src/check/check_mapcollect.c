/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapcollect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:39:58 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/12 13:52:37 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_hole(char **map, int i, int j, int deadline)
{
	if ((!map[i + 1] && map[i][j] == '0') || map[i][j] == ' '
		|| map[i][j] == '\0' || (map[i][j] == '\0' && j == 0)
		|| deadline > 1000)
		return (true);
	if (j < 0 || i < 0 || !map[i] || map[i][j] == '\0'
		|| map[i][j] == '1' || map[i][j] == '2')
		return (false);
	if (map[i][j] == '0')
		map[i][j] = '2';
	if (check_hole(map, i + 1, j, ++deadline))
		return (true);
	if (check_hole(map, i - 1, j, ++deadline))
		return (true);
	if (check_hole(map, i, j + 1, ++deadline))
		return (true);
	if (check_hole(map, i, j - 1, ++deadline))
		return (true);
	return (--deadline, false);
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
	if (check_hole(map + border, i - border, j, 0))
		exit_error(HOLE_MAP_ERROR, mapdata, map);
}
