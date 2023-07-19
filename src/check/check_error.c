/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:07 by rnaka             #+#    #+#             */
/*   Updated: 2023/07/19 19:15:26 by rnaka            ###   ########.fr       */
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

static char	**get_mapfile(int fd)
{
	int	size;
	char	**map;
	char	**save;
	char	*stock;

	map = NULL;
	stock = get_next_line(fd);
	if (!stock)
		error(2);
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

void	check_error(const int argc, const char **argv)
{
	int	fd;
	char	**mapfile;

	file_name(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error(2);
	mapfile = get_mapfile(fd);
	printf("NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN\n");
	check_mapfile(mapfile);
}
