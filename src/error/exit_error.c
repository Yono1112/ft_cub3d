#include "cub3d.h"

void	exit_error(char *str)
{
	if (str)
	{
		while (*str)
			write(STDERR_FILENO, &*str++, 1);
		write(STDERR_FILENO, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
