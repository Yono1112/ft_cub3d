/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:07 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/26 21:25:02 by yumaohno         ###   ########.fr       */
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

static void	free_map_last_line(char **map)
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
		exit_error(READFILE_ERROR, NULL, NULL);
	size = 0;
	while (stock)
	{
		size++;
		save = (char **)malloc(sizeof(char *) * (size + 1));
		chardp_mig(map, save);
		save[size - 1] = stock;
		save[size] = NULL;
		free_map_last_line(map);
		map = save;
		stock = get_next_line(fd);
	}
	return (map);
}

static void	init_mapdata(t_map *mapdata)
{
	mapdata->no = NULL;
	mapdata->so = NULL;
	mapdata->ea = NULL;
	mapdata->we = NULL;
	mapdata->floor = NULL;
	mapdata->ceiling = NULL;
	mapdata->map = NULL;
}

void	check_error(const int argc, const char **argv, t_map *mapdata)
{
	int	fd;
	char	**mapfile;

	init_mapdata(mapdata);
	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_error(FILENAME_ERROR, NULL, NULL);
	mapfile = read_mapfile(fd);
	close(fd);
	check_mapfile(mapfile, mapdata);
	free_map(mapfile);
}
