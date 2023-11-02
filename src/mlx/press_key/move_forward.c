/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:11:14 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/02 20:19:04 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_mlx *mlx)
{
	double	dist_to_wall;

	dist_to_wall = calc_dist_to_wall(mlx, mlx->player_direct);
	if (dist_to_wall > MOVE_SPEED * 2)
	{
		mlx->pos_y = mlx->pos_y + sin(mlx->player_direct) * MOVE_SPEED;
		mlx->pos_x = mlx->pos_x + cos(mlx->player_direct) * MOVE_SPEED;
	}
}
