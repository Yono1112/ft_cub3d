/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:13:04 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:18:01 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_mlx *mlx)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(-MOVE_SPEED) - mlx->dir_y * sin(-MOVE_SPEED);
	mlx->dir_y = old_dir_x * sin(-MOVE_SPEED) + mlx->dir_y * cos(-MOVE_SPEED);
	old_plane_x = mlx->plane_x;
	mlx->plane_x
		= mlx->plane_x * cos(-MOVE_SPEED) - mlx->plane_y * sin(-MOVE_SPEED);
	mlx->plane_y
		= old_plane_x * sin(-MOVE_SPEED) + mlx->plane_y * cos(-MOVE_SPEED);
}
