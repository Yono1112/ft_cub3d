/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_to_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:08:53 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 03:23:31 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_initial_step(t_mlx *mlx)
{
	if (mlx->ray_dir_x < 0)
	{
		mlx->step_x = -1;
		mlx->side_dist_x = (mlx->pos_x - mlx->map_x) * mlx->delta_dist_x;
	}
	else
	{
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
		mlx->step_y = 1;
		mlx->side_dist_y = (mlx->map_y + 1.0 - mlx->pos_y) * mlx->delta_dist_y;
	}
}

static void	calc_dda_algorithm(t_mlx *mlx)
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

static void	calc_delta_dist(t_mlx *mlx)
{
	if (!mlx->ray_dir_x)
		mlx->delta_dist_x = 1e30;
	else
		mlx->delta_dist_x = sqrt(1 + (mlx->ray_dir_y * mlx->ray_dir_y)
				/ (mlx->ray_dir_x * mlx->ray_dir_x));
	if (!mlx->ray_dir_y)
		mlx->delta_dist_y = 1e30;
	else
		mlx->delta_dist_y = sqrt(1 + (mlx->ray_dir_x * mlx->ray_dir_x)
				/ (mlx->ray_dir_y * mlx->ray_dir_y));
}

double	calc_dist_to_wall(t_mlx *mlx, double ray_direct)
{
	mlx->map_x = (int)mlx->pos_x;
	mlx->map_y = (int)mlx->pos_y;
	mlx->ray_dir_x = cos(ray_direct);
	mlx->ray_dir_y = sin(ray_direct);
	calc_delta_dist(mlx);
	calc_initial_step(mlx);
	calc_dda_algorithm(mlx);
	if (mlx->side == SIDE_X)
		return ((mlx->map_x - mlx->pos_x + (1 - mlx->step_x) / 2)
			/ mlx->ray_dir_x);
	else
		return ((mlx->map_y - mlx->pos_y + (1 - mlx->step_y) / 2)
			/ mlx->ray_dir_y);
}
