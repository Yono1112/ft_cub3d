/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:22:33 by rnaka             #+#    #+#             */
/*   Updated: 2023/11/15 20:15:07 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_num_coma(char *str)
{
	int	i;
	int	commma_num;

	i = 0;
	commma_num = 0;
	while (str[i])
	{
		if (commma_num > 2 || (!ft_isdigit(str[i])
				&& str[i] != ',' && str[i] != '\n')
			|| (str[i] == ',' && !ft_isdigit(str[i + 1])))
			return (false);
		if (str[i] == '\n')
			str[i] = '\0';
		if (str[i] == ',' )
			commma_num++;
		i++;
	}
	if (commma_num < 2)
		return (false);
	return (true);
}

bool	free_split(char **split1, char **split2)
{
	free_map(split1);
	free_map(split2);
	return (false);
}

void	split_number(t_map *mapdata, char ***array_ceiling, char ***array_floor)
{
	int	i;

	i = 0;
	*array_floor = ft_split(mapdata->floor, ',');
	*array_ceiling = ft_split(mapdata->ceiling, ',');
	if (!*array_floor || !*array_ceiling)
		exit_error(MALLOC_ERROR, mapdata, NULL);
	while ((*array_ceiling)[i] && (*array_floor)[i])
		i++;
	if (i != 3)
	{
		free_split(*array_ceiling, *array_floor);
		exit_error(TEXTURE_ERROR, mapdata, NULL);
	}
}

int	set_number(t_map *mapdata)
{
	char	**array_ceiling;
	char	**array_floor;
	int		num_ceiling;
	int		num_floor;
	int		i;

	i = 0;
	split_number(mapdata, &array_ceiling, &array_floor);
	while (array_ceiling[i] && array_floor[i])
	{
		num_ceiling = 0;
		num_floor = 0;
		num_ceiling = ft_atol(array_ceiling[i], &num_ceiling);
		num_floor = ft_atol(array_floor[i], &num_floor);
		if (num_ceiling < 0 || num_floor < 0
			|| num_ceiling > 255 || num_floor > 255)
			return (free_split(array_ceiling, array_floor));
		mapdata->floor_num[i] = num_floor;
		mapdata->ceiling_num[i++] = num_ceiling;
	}
	free_split(array_ceiling, array_floor);
	return (true);
}

void	check_floor_ceiling(char **map, t_map *mapdata)
{
	mapdata->floor = removechr(mapdata->floor, ' ');
	mapdata->ceiling = removechr(mapdata->ceiling, ' ');
	if (!check_num_coma(mapdata->floor) || !check_num_coma(mapdata->ceiling))
		exit_error(FLOOR_CEILING_ERROR, mapdata, map);
	if (!set_number(mapdata))
		exit_error(TEXTURE_BIG_ERROR, mapdata, map);
}
