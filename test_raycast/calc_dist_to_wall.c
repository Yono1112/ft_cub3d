#include "test_raycast.h"

void	calc_initial_step(t_mlx *mlx)
{
	if (mlx->ray_dir_x < 0)
	{
		mlx->step_x = -1;
		mlx->side_dist_x = (mlx->pos_x - mlx->map_x) * mlx->delta_dist_x;
	}
	else
	{
		// printf("%d, %f\n", mlx->map_x, mlx->pos_x);
		mlx->step_x = 1;
		mlx->side_dist_x = (mlx->map_x + 1.0 - mlx->pos_x) * mlx->delta_dist_x;
	}
	if (mlx->ray_dir_y < 0)
	{
		mlx->step_y = -1;
		mlx->side_dist_y = (mlx->pos_y - mlx->map_y) * mlx->delta_dist_y;
	}
	else
	{
		// printf("%d, %f\n", mlx->map_y, mlx->pos_y);
		mlx->step_y = 1;
		mlx->side_dist_y = (mlx->map_y + 1.0 - mlx->pos_y) * mlx->delta_dist_y;
	}
}

void	calc_dda_algorithm(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->side_dist_x < mlx->side_dist_y)
		{
			mlx->side_dist_x += mlx->delta_dist_x;
			mlx->map_x += mlx->step_x;
			mlx->side = SIDE_X;
		}
		else
		{
			mlx->side_dist_y += mlx->delta_dist_y;
			mlx->map_y += mlx->step_y;
			mlx->side = SIDE_Y;
		}
		if (world_map[mlx->map_y][mlx->map_x] != '0')
			break ;
	}
}

void	calc_dist_to_wall(t_mlx *mlx)
{
	calc_initial_step(mlx);
	calc_dda_algorithm(mlx);
	if (mlx->side == SIDE_X)
	{
		mlx->dist_to_wall = (mlx->map_x - mlx->pos_x + (1 - mlx->step_x) / 2) / mlx->ray_dir_x;
		// mlx->dist_to_wall = (mlx->side_dist_x - mlx->delta_dist_x);
	}
	else
	{
		mlx->dist_to_wall = (mlx->map_y - mlx->pos_y + (1 - mlx->step_y) / 2) / mlx->ray_dir_y;
		// mlx->dist_to_wall = (mlx->side_dist_y - mlx->delta_dist_y);
	}
	// printf("\n%f, %f\n", mlx->ray_dir_x, mlx->ray_dir_y);
	// exit(0);
}
