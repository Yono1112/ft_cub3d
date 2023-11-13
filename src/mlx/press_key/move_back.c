/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:11:49 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:16:33 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_back(t_mlx *mlx)
{
	double	back_dir_x;
	double	back_dir_y;

	back_dir_x = -mlx->dir_x;
	back_dir_y = -mlx->dir_y;
	if (mlx->mapdata->map[(int)(mlx->pos_y + back_dir_y * MOVE_SPEED)]
		[(int)mlx->pos_x] == '0')
		mlx->pos_y += back_dir_y * MOVE_SPEED;
	if (mlx->mapdata->map[(int)(mlx->pos_y)]
		[(int)(mlx->pos_x + back_dir_x * MOVE_SPEED)] == '0')
		mlx->pos_x += back_dir_x * MOVE_SPEED;
}
