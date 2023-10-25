#include "cub3d.h"

void	error(char *str)
{
	write(STDERR_FILENO, "\e[31mERROR\e[m: ", ft_strlen("\e[31mERROR\e[m: "));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
