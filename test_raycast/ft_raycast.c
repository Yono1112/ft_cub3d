#include "test_raycast.h"

int	ft_raycast(t_mlx *mlx)
{
	size_t	x;

	x = 0;
	while (x < WINSIZE_WIDTH)
	{
		mlx->camera_x = 0;
		calc_dist_to_wall(mlx);
		draw_wall_texture(mlx, x);
		x++;
	}
	return (0);
}
