/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapcollect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:39:58 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/31 20:46:52 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_hole(char **map, int i, int j, int border)
{
	if ((!map[i + 1] && map[i][j] == '0') || map[i][j] == ' '
		|| map[i][j] == '\0' || (map[i][j] == '\0' && j == 0))
		return (true);
	if (j < 0 || i < border || !map[i] || map[i][j] == '\0'
		|| map[i][j] == '1' || map[i][j] == '2')
		return (false);
	if (map[i][j] == '0')
		map[i][j] = '2';
	if (check_hole(map, i + 1, j, border))
		return (true);
	if (check_hole(map, i - 1, j, border))
		return (true);
	if (check_hole(map, i, j + 1, border))
		return (true);
	if (check_hole(map, i, j - 1, border))
		return (true);
	return (false);
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
	if (check_hole(map, i, j, border))
		exit_error(HOLE_MAP_ERROR, mapdata, map);
}
