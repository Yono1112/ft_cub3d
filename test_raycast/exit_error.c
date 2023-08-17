#include "test_raycast.h"

void	exit_error(char *str)
{
	if (str)
		while (*str)
			write(2, &*str++, 1);
	exit(EXIT_FAILURE);
}
