/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/07/20 22:50:28 by rnaka            ###   ########.fr       */
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

void	check_texture(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (!ft_isalpha(map[i][j]) && map[i][j])
			j++;
		if (ft_isalpha(map[i][j]))
			break ;
		i++;
	}
	printf("%s",check_north(map[i]));
	i++;
	while (map[i])
	{
		j = 0;
		while (!ft_isalpha(map[i][j]) && map[i][j])
			j++;
		if (ft_isalpha(map[i][j]))
			break ;
		i++;
	}
	printf("%s",check_south(map[i]));
	i++;
	while (map[i])
	{
		j = 0;
		while (!ft_isalpha(map[i][j]) && map[i][j])
			j++;
		if (ft_isalpha(map[i][j]))
			break ;
		i++;
	}
	printf("%s",check_east(map[i]));
	i++;
	while (map[i])
	{
		j = 0;
		while (!ft_isalpha(map[i][j]) && map[i][j])
			j++;
		if (ft_isalpha(map[i][j]))
			break ;
		i++;
	}
	printf("%s",check_west(map[i]));
}

void	check_mapfile(char **map)
{
	check_texture(map);
	// check-map(map);
}
