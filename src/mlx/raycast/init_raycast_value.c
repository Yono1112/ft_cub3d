/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:09:09 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:09:10 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	init_raycast_value(t_mlx *mlx, size_t x)
{
	mlx->ray_direct = calc_ray_direct(mlx, x);
	mlx->dist_to_wall = calc_dist_to_wall(mlx, mlx->ray_direct);
	// mlx->ray_dir_x = cos(mlx->ray_direct);
	// mlx->ray_dir_y = sin(mlx->ray_direct);
	// // printf("mlx->ray_dir_x: %f, mlx->ray_dir_y: %f, mlx->delta_dist_y: %f\n", mlx->ray_dir_x, mlx->ray_dir_y, mlx->delta_dist_y);
	// if (!mlx->ray_dir_x)
	// 	mlx->delta_dist_x = 1e30;
	// else
	// {
	// 	mlx->delta_dist_x = sqrt(1 + (mlx->ray_dir_y * mlx->ray_dir_y)
	// 			/ (mlx->ray_dir_x * mlx->ray_dir_x));
	// 	// printf("1 / mlx->ray_dir_x: %f\n", 1 / mlx->ray_dir_x);
	// 	// mlx->delta_dist_x = fabs(1 / mlx->ray_dir_x);
	// }
	// if (!mlx->ray_dir_y)
	// 	mlx->delta_dist_y = 1e30;
	// 	// mlx->delta_dist_y = DBL_MAX;
	// else
	// {
	// 	mlx->delta_dist_y = sqrt(1 + (mlx->ray_dir_x * mlx->ray_dir_x)
	// 			/ (mlx->ray_dir_y * mlx->ray_dir_y));
	// 	// printf("1 / mlx->ray_dir_y: %f\n", 1 / mlx->ray_dir_y);
	// 	// mlx->delta_dist_y = fabs(1 / mlx->ray_dir_y);
	// }
}