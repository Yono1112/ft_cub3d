/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:09:06 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/05 17:28:31 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_move_rotate(t_mlx *mlx)
{
	if (mlx->key_w)
		move_forward(mlx);
	if (mlx->key_s)
		move_back(mlx);
	if (mlx->key_a)
		move_left(mlx);
	if (mlx->key_d)
		move_right(mlx);
	if (mlx->key_arrow_left)
		rotate_left(mlx);
	if (mlx->key_arrow_right)
		rotate_right(mlx);
}

int	ft_raycast(t_mlx *mlx)
{
	size_t	x;

	check_move_rotate(mlx);
	x = 0;
	while (x < WINSIZE_WIDTH)
	{
		calc_wall_height(mlx, x);
		draw_wall_texture_ceiling_floor(mlx, x);
		x++;
	}
	return (0);
}
