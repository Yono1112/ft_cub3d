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
	else if (error_num == 5)
		printf("Direction error.\n");
	else if (error_num == 6)
		printf("not enogh arguments.\n");
	else if (error_num == 7)
		printf("ceiling or floor arguments is invalid.\n");
	else if (error_num == 8)
		printf("invalid arguments in map.\n");
	else if (error_num == 9)
		printf("invalid number of news.\n");
	else if (error_num == 10)
		printf("there is hole in map.\n");
	exit(1);
}
