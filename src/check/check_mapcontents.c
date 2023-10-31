/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapcontents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:42:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/31 20:10:19 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_news(char **map, int i, int j)
{
	if (map[i][j] == 'N' || map[i][j] == 'E'
					|| map[i][j] == 'W' || map[i][j] == 'S' )
		return (true);
	else
		return (false);
}

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
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& !is_news(map, i, j))
				exit_error(MAP_ARGUMENT_ERROR, mapdata, map);
			if (is_news(map, i, j))
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
