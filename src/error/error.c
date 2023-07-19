#include "cub3d.h"

void	error(int error_num)
{
	printf("\e[31mERROR\e[m");
	if (error_num)
		printf("Missing required arguments.\n");
	exit(1);
}
