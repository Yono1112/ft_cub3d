#include"cub3d.h"

void	check_north(map)
{
	
}

void	check_texture(char **map)
{
	check_north(map);
	check_south(map);
	check_east(map);
	check_west(map);
}

void	check_mapfile(char **map)
{
	printf("%s\n\n", argv[1]);
	check_texture(argv);
	// check-map(argv);
}
