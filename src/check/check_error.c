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

	if (argc != 2)
		error(1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		error(2);
	mapfile = get_mapfile(fd);
	check_mapfile(mapfile);
}
