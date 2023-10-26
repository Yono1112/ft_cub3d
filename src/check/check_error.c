/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:07 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/25 20:41:28 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	chardp_mig(char **map, char **save)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		save[i] = map[i];
		i++;
	}
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		i++;
	free(map[i]);
	free(map);
}

static char	**read_mapfile(int fd)
{
	int	size;
	char	**map;
	char	**save;
	char	*stock;

	map = NULL;
	stock = get_next_line(fd);
	if (!stock)
		error(READFILE_ERROR);
	size = 0;
	while (stock)
	{
		size++;
		save = (char **)malloc(sizeof(char *) * (size + 1));
		chardp_mig(map, save);
		save[size - 1] = stock;
		save[size] = NULL;
		free_map(map);
		map = save;
		stock = get_next_line(fd);
	}
	return (map);
}

void	check_error(const int argc, const char **argv, t_map *mapdata)
{
	int	fd;
	char	**mapfile;

	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(FILENAME_ERROR);
	mapfile = read_mapfile(fd);
	check_mapfile(mapfile, mapdata);
}
