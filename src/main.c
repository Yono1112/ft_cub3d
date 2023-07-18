#include"cub3d.h"

int main(int argc, char **argv)
{
	int	i;

	i = argc;
	argc++;
	argc = i;
	check_error((const int)argc, (const char**)argv);
	printf("%s\n",argv[1]);
	return (0);
}
