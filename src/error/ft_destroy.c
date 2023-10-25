#include "cub3d.h"

int	ft_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	write(STDOUT_FILENO, DESTROY_PREFIX, ft_strlen(DESTROY_PREFIX));
	// if (str)
	// 	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
	// printf("FINISH: %s\n", str);
	exit(EXIT_SUCCESS);
}
