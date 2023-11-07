/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:12:48 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:13:13 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_mlx *mlx)
{
	double	right_dir_x;
	double	right_dir_y;

	right_dir_x = -mlx->dir_y;
	right_dir_y = mlx->dir_x;
	if (mlx->mapdata->map[(int)(mlx->pos_y + right_dir_y * MOVE_SPEED)]
		[(int)mlx->pos_x] == '0')
		mlx->pos_y += right_dir_y * MOVE_SPEED;
	if (mlx->mapdata->map[(int)(mlx->pos_y)]
		[(int)(mlx->pos_x + right_dir_x * MOVE_SPEED)] == '0')
		mlx->pos_x += right_dir_x * MOVE_SPEED;
}
