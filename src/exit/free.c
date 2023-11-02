/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:39 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/01 15:40:22 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_data(t_map *mapdata, char **map)
{
	if (map)
		free_map(map);
	if (mapdata->no)
		free(mapdata->no);
	if (mapdata->ea)
		free(mapdata->ea);
	if (mapdata->so)
		free(mapdata->so);
	if (mapdata->we)
		free(mapdata->we);
	if (mapdata->floor)
		free(mapdata->floor);
	if (mapdata->ceiling)
		free(mapdata->ceiling);
}
