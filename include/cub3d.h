#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include<stdlib.h>
#include <fcntl.h>

//check-mapfile
void	error(int error_num);
void	check_error(const int argc, const char **argv);
void	check_mapfile(char **argv);
void	file_name(const int argc, const char **argv);
#endif
