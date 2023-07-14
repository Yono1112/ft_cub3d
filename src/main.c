#include"cub3d.h"

int main(int argc, char **argv)
{
	int	i;

	i = argc;
	argc++;
	argc = i;
	check_mapfile(argv);
	printf("%s\n",argv[1]);
	return (0);
}
