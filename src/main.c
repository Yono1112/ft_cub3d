#include"cub3d.h"

int main(int argc, char **argv)
{
	int	i;
	t_map	mapdata;

	i = argc;
	argc++;
	argc = i;
	check_error((const int)argc, (const char**)argv, &mapdata);
	return (0);
}
