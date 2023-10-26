/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_to_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:08:53 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:08:54 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (mlx->mapdata->map[mlx->map_y][mlx->map_x] != '0')
			break ;
	}
}

void	calc_delta_dist(t_mlx *mlx)
{
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

double	calc_dist_to_wall(t_mlx *mlx, double ray_direct)
{
	mlx->map_x = (int)mlx->pos_x;
	mlx->map_y = (int)mlx->pos_y;
	mlx->ray_dir_x = cos(ray_direct);
	mlx->ray_dir_y = sin(ray_direct);
	// printf("mlx->ray_dir_x: %f, mlx->ray_dir_y: %f, mlx->delta_dist_y: %f\n", mlx->ray_dir_x, mlx->ray_dir_y, mlx->delta_dist_y);
	calc_delta_dist(mlx);
	calc_initial_step(mlx);
	calc_dda_algorithm(mlx);
	if (mlx->side == SIDE_X)
	{
		return (mlx->map_x - mlx->pos_x + (1 - mlx->step_x) / 2) / mlx->ray_dir_x;
		// mlx->dist_to_wall = (mlx->side_dist_x - mlx->delta_dist_x);
	}
	else
	{
		return (mlx->map_y - mlx->pos_y + (1 - mlx->step_y) / 2) / mlx->ray_dir_y;
		// mlx->dist_to_wall = (mlx->side_dist_y - mlx->delta_dist_y);
	}
	// printf("\n%f, %f\n", mlx->ray_dir_x, mlx->ray_dir_y);
	// exit(0);
}
