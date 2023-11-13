/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:11:14 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:14:32 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_mlx *mlx)
{
	if (mlx->mapdata->map[(int)(mlx->pos_y + mlx->dir_y * MOVE_SPEED)]
		[(int)mlx->pos_x] == '0')
		mlx->pos_y += mlx->dir_y * MOVE_SPEED;
	if (mlx->mapdata->map[(int)(mlx->pos_y)]
		[(int)(mlx->pos_x + mlx->dir_x * MOVE_SPEED)] == '0')
		mlx->pos_x += mlx->dir_x * MOVE_SPEED;
}
