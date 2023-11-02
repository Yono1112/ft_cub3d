/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:12:48 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/02 14:50:57 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_mlx *mlx)
{
	double	dist_to_wall;

	printf("press D key: move_right\n");
	printf("before mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	dist_to_wall = calc_dist_to_wall(mlx,
			(mlx->player_direct + 90 * (M_PI / 180)));
	printf("dist_to_wall: %f\n", dist_to_wall);
	if (dist_to_wall > MOVE_SPEED * 1.15)
	{
		mlx->pos_x = mlx->pos_x - MOVE_SPEED * sin(mlx->player_direct);
		mlx->pos_y = mlx->pos_y + MOVE_SPEED * cos(mlx->player_direct);
		printf("after mlx->pos_x: %lf, mlx->pos_y: %lf\n",
			mlx->pos_x, mlx->pos_y);
	}
	else
		printf("cannnot move right\n");
	printf("----------------------------------------\n");
}
