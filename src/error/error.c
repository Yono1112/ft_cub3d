#include "cub3d.h"

void	error(int error_num)
{
	printf("\e[31mERROR\e[m");
	if (error_num == 1)
		printf("Missing required arguments.\n");
	else if (error_num == 2)
		printf("Missing filename.\n");
	else if (error_num == 3)
		printf("I can't open the file.\n");
	else if (error_num == 4)
		printf("I can't read the file.\n");
	exit(1);
}
