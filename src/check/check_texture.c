/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:45:16 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/14 21:19:07 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_null_texture(t_map *mapdata)
{
	if (!mapdata->no || !mapdata->ea || !mapdata->we || !mapdata->so
		|| !mapdata->ceiling || !mapdata->floor)
		return (true);
	return (false);
}

void	initialize_texture(t_map *mapdata)
{
	mapdata->no = NULL;
	mapdata->so = NULL;
	mapdata->ea = NULL;
	mapdata->we = NULL;
	mapdata->ceiling = NULL;
	mapdata->floor = NULL;
}

void	remove_space_after_texture(char *line)
{
	int	i;
	int	last_chr;

	i = 0;
	last_chr = 0;
	if (!line)
		return ;
	while (line[i])
	{
		if (line[i] != ' ')
			last_chr = i;
		i++;
	}
	line[last_chr + 1] = '\0';
}

int	check_texture(char **map, t_map *mapdata)
{
	int	i;
	int	five_texture;

	i = 0;
	five_texture = 0;
	initialize_texture(mapdata);
	while (five_texture <= 5)
	{
		skip_space(map, &i, mapdata);
		check_direction(map[i], map, mapdata);
		i++;
		five_texture++;
	}
	skip_space(map, &i, mapdata);
	if (is_null_texture(mapdata))
		exit_error(TEXTURE_ERROR, mapdata, map);
	remove_space_after_texture(mapdata->no);
	remove_space_after_texture(mapdata->so);
	remove_space_after_texture(mapdata->ea);
	remove_space_after_texture(mapdata->we);
	return (i);
}
