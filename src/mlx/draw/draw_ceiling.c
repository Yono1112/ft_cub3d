/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:41:47 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:41:55 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(int x, int y, void *mlx_ptr, void *mlx_win)
{
	long	color_ceiling;

	color_ceiling = (0 * 65536) + (0 * 256) + 0;
	mlx_pixel_put(mlx_ptr, mlx_win, x, y, color_ceiling);
}
