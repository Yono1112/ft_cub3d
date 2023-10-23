#include "cub3d.h"

void	error(int error)
{
	printf("\e[31mERROR\e[m");
	if (error == Argument_Error)
		printf("Missing required arguments.\n");
	else if (error == Filename_Error)
		printf("Missing filename.\n");
	else if (error == Openfile_Error)
		printf("I can't open the file.\n");
	else if (error == Readfile_Error)
		printf("I can't read the file.\n");
	else if (error == Texture_Error)
		printf("Texture error.\n");
	else if (error == Mapargument_Error)//num_map_argument_error
		printf("not enogh arguments.\n");
	else if (error == Invalid_Argument_In_Map_Error)
		printf("invalid arguments in map.\n");
	else if (error == Num_Arguments_Error)
		printf("invalid number of news.\n");
	else if (error == Hole_In_Map)
		printf("there is hole in map.\n");
	else if (error == Open_Texture_Error)
		printf("can't open the texture.\n");
	else if (error == Comma_Error)
		printf("commma error.\n");
	else if (error == Texture_is_big)
		printf("texture number error.\n");
	exit(1);
}
