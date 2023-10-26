#include"cub3d.h"

int main(int argc, char **argv)
{
	int		i;
	t_map	mapdata;

	i = argc;
	argc++;
	argc = i;
	check_error((const int)argc, (const char**)argv, &mapdata);
	// print_map(mapdata.map);
	run_mlx(&mapdata);
	exit(0);
}

__attribute__((destructor))
static void destructor(void){
			system("leaks -q cub3D");
			}
