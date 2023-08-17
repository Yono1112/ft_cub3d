#include "test_raycast.h"

void	calc_dist_to_wall(t_mlx *mlx)
{
	(void)mlx;
}

void	draw_wall_texture(t_mlx *mlx, size_t x)
{
	(void)mlx;
	(void)x;
}

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
