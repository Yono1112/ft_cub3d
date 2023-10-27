#include"cub3d.h"
void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("start print_map\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("finish print_map\n");
}

int main(int argc, char **argv)
{
	int		i;
	t_map	mapdata;

	i = argc;
	argc++;
	argc = i;
	check_error((const int)argc, (const char**)argv, &mapdata);
<<<<<<< HEAD
	print_map(mapdata.map);
	exit (0);
=======
	run_mlx(&mapdata);
	exit(0);
>>>>>>> develop
}

__attribute__((destructor))
static void destructor(void){
			system("leaks -q cub3D");
			}
