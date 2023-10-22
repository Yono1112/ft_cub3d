#include "test_raycast.h"
#include <float.h>

double	calc_ray_direct(t_mlx *mlx, size_t x)
{
	double	angle;
	double	left_fov_angle;
	double	angle_offset;

	left_fov_angle = mlx->player_direct - (FOV / 2);
	angle_offset = ((double)x / (double)WINSIZE_WIDTH) * FOV;
	angle = left_fov_angle + angle_offset;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	init_mlx_value(t_mlx *mlx, size_t x)
{
	mlx->map_x = (int)mlx->pos_x;
	mlx->map_y = (int)mlx->pos_y;
	mlx->ray_direct = calc_ray_direct(mlx, x);
	mlx->ray_dir_x = cos(mlx->ray_direct);
	mlx->ray_dir_y = sin(mlx->ray_direct);
	// printf("mlx->ray_dir_x: %f, mlx->ray_dir_y: %f, mlx->delta_dist_y: %f\n", mlx->ray_dir_x, mlx->ray_dir_y, mlx->delta_dist_y);
	if (!mlx->ray_dir_x)
		mlx->delta_dist_x = 1e30;
	else
	{
		mlx->delta_dist_x = sqrt(1 + (mlx->ray_dir_y * mlx->ray_dir_y)
				/ (mlx->ray_dir_x * mlx->ray_dir_x));
		// printf("1 / mlx->ray_dir_x: %f\n", 1 / mlx->ray_dir_x);
		// mlx->delta_dist_x = fabs(1 / mlx->ray_dir_x);
	}
	if (!mlx->ray_dir_y)
		mlx->delta_dist_y = 1e30;
		// mlx->delta_dist_y = DBL_MAX;
	else
	{
		mlx->delta_dist_y = sqrt(1 + (mlx->ray_dir_x * mlx->ray_dir_x)
				/ (mlx->ray_dir_y * mlx->ray_dir_y));
		// printf("1 / mlx->ray_dir_y: %f\n", 1 / mlx->ray_dir_y);
		// mlx->delta_dist_y = fabs(1 / mlx->ray_dir_y);
	}
}

int	ft_raycast(t_mlx *mlx)
{
	size_t	x;

	x = 0;
	while (x < WINSIZE_WIDTH)
	{
		init_mlx_value(mlx, x);
		calc_dist_to_wall(mlx);
		// printf("%ld: %f(%f°), %f(%f°)\n", x, mlx->player_direct, mlx->player_direct * (180 / M_PI), mlx->ray_direct, mlx->ray_direct * (180 / M_PI));
		// printf("dist_to_wall:%f(%f°)\n", mlx->dist_to_wall, mlx->ray_direct * (180 / M_PI));
		draw_wall_texture_ceiling_floor(mlx, x);
		x++;
	}
	// exit(0);
	return (0);
}
