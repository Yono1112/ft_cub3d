/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:41:47 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/29 17:28:00 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(int x, int y, int ceiling_num[3], t_mlx *mlx)
{
	long	color_ceiling;

	color_ceiling
		= (ceiling_num[0] * 65536) + (ceiling_num[1] * 256) + ceiling_num[2];
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, color_ceiling);
}
