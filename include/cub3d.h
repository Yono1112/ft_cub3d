#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include<stdlib.h>
#include <fcntl.h>


typedef struct s_map
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *floor;
	char *ceiling;
	char **map;
}t_map;
//check-mapfile
void	error(int error_num);
void	check_error(const int argc, const char **argv,t_map *mapdata);
void	check_mapfile(char **argv, t_map *mapdata);
void	file_name(const int argc, const char **argv);
#endif
