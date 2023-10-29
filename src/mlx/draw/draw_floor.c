/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:41:27 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:41:36 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(int x, int y, void *mlx_ptr, void *mlx_win, int floor_num[3])
{
	long	color_floor;

	color_floor = (floor_num[0] * 65536) + (floor_num[1] * 256) + floor_num[2];
	mlx_pixel_put(mlx_ptr, mlx_win, x, y, color_floor);
}
