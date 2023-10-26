#include "cub3d.h"

int	ft_destroy(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	while (i < 4)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_texture[i++].img_ptr);
	free_data(mlx->mapdata, mlx->mapdata->map);
	write(STDOUT_FILENO, DESTROY_PREFIX, ft_strlen(DESTROY_PREFIX));
	// if (str)
	// 	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
	// printf("FINISH: %s\n", str);
	exit(EXIT_SUCCESS);
}
