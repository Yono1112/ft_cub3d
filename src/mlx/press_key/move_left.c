/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:12:29 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:43:35 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_mlx *mlx)
{
	double	left_dir_x;
	double	left_dir_y;

	left_dir_x = mlx->dir_y;
	left_dir_y = -mlx->dir_x;
	if (mlx->mapdata->map[(int)(mlx->pos_y + left_dir_y * MOVE_SPEED)]
		[(int)mlx->pos_x] == '0')
		mlx->pos_y += left_dir_y * MOVE_SPEED;
	if (mlx->mapdata->map[(int)(mlx->pos_y)]
		[(int)(mlx->pos_x + left_dir_x * MOVE_SPEED)] == '0')
		mlx->pos_x += left_dir_x * MOVE_SPEED;
}
