/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:11:49 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/02 14:51:27 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_back(t_mlx *mlx)
{
	double	dist_to_wall;

	printf("press S key: move_back\n");
	printf("before mlx->pos_x: %lf, mlx->pos_y: %lf\n", mlx->pos_x, mlx->pos_y);
	dist_to_wall = calc_dist_to_wall(mlx,
			(mlx->player_direct - 180 * (M_PI / 180)));
	printf("dist_to_wall: %f\n", dist_to_wall);
	if (dist_to_wall > MOVE_SPEED * 2)
	{
		mlx->pos_x = mlx->pos_x - MOVE_SPEED * cos(mlx->player_direct);
		mlx->pos_y = mlx->pos_y - MOVE_SPEED * sin(mlx->player_direct);
		printf("after mlx->pos_x: %lf, mlx->pos_y: %lf\n",
			mlx->pos_x, mlx->pos_y);
	}
	else
		printf("cannnot move back\n");
	printf("----------------------------------------\n");
}
