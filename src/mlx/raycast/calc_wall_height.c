/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:09:09 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 03:22:36 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	calc_ray_direct(t_mlx *mlx, size_t x)
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

void	calc_wall_height(t_mlx *mlx, size_t x)
{
	mlx->ray_direct = calc_ray_direct(mlx, x);
	mlx->dist_to_wall = calc_dist_to_wall(mlx, mlx->ray_direct);
	mlx->wall_height = WINSIZE_HEIGTH / mlx->dist_to_wall;
}
