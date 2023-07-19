#include "cub3d.h"

void	error(int error_num)
{
	printf("\e[31mERROR\e[m");
	if (error_num == 1)
		printf("Missing required arguments.\n");
	if (error_num == 2)
		printf("Missing filename.\n");
	exit(1);
}
