#include "test_raycast.h"

double	calc_ray_direct(t_mlx *mlx, size_t x)
{
	double	angle;
	double	left_fov_angle;
	double	angle_offset;

	left_fov_angle = mlx->player_direct - (FOV / 2);
	angle_offset = ((double)x / WINSIZE_WIDTH) * FOV;
	angle = left_fov_angle + angle_offset;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	ft_raycast(t_mlx *mlx)
{
	size_t	x;

	x = 0;
	while (x < WINSIZE_WIDTH)
	{
		mlx->ray_direct = calc_ray_direct(mlx, x);
		// printf("%ld: %f(%f°), %f(%f°)\n", x, mlx->player_direct, mlx->player_direct * (180 / M_PI), mlx->ray_direct, mlx->ray_direct * (180 / M_PI));
		calc_dist_to_wall(mlx);
		draw_wall_texture(mlx, x);
		x++;
	}
	exit(0);
	return (0);
}
