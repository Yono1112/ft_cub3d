#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include<stdlib.h>
#include <fcntl.h>
#include <stdbool.h>


typedef struct s_map
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *floor;
	char *ceiling;
	char **map;
	char *ceiling_num_char[3];
	char *floor_num_char[3];
}t_map;

enum Error {
	Argument_Error,
	Openfile_Error,
	Filename_Error,
	Readfile_Error,
	Mapargument_Error,
	Texture_Error,
	Invalid_Argument_In_Map_Error,
	Num_Arguments_Error,
	Hole_In_Map,
	Open_Texture_Error,
	Comma_Error,
	Texture_is_big
};

//check-mapfile
void	error(int error_num);
void	check_error(const int argc, const char **argv,t_map *mapdata);
void	check_mapfile(char **argv, t_map *mapdata);
void	file_name(const int argc, const char **argv);
#endif
