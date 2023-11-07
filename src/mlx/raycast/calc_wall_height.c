/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:09:09 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:22:02 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_height(t_mlx *mlx, size_t x)
{
	mlx->camera_x = 2 * x / (double)WINSIZE_WIDTH - 1;
	mlx->dist_to_wall = calc_dist_to_wall(mlx);
	mlx->wall_height = WINSIZE_HEIGTH / mlx->dist_to_wall;
}
