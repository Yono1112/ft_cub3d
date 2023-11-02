/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_texture_ceiling_floor.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:08:58 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/01 15:30:08 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_draw_start_end(double wall_height, double *start, double *end)
{
	*start = -1 * wall_height / 2.0 + (double)WINSIZE_HEIGTH / 2.0;
	if (*start < 0)
		*start = 0;
	*end = wall_height / 2.0 + (double)WINSIZE_HEIGTH / 2.0;
	if (*end >= WINSIZE_HEIGTH)
		*end = WINSIZE_HEIGTH - 1;
}

static bool	is_ceiling(int y, double draw_start)
{
	return (y < draw_start);
}

static bool	is_floor(int y, double draw_end)
{
	return (y > draw_end);
}

void	draw_wall_texture_ceiling_floor(t_mlx *mlx, size_t x)
{
	int		y;
	double	draw_start;
	double	draw_end;

	y = 0;
	set_draw_start_end(mlx->wall_height, &draw_start, &draw_end);
	mlx->step = 1.0 * TEX_HEIGHT / mlx->wall_height;
	mlx->wall_y = (draw_start - WINSIZE_HEIGTH / 2 + mlx->wall_height / 2)
		* mlx->step;
	while (y < WINSIZE_HEIGTH)
	{
		if (is_ceiling(y, draw_start))
			draw_ceiling(x, y, mlx->mapdata->ceiling_num, mlx);
		else if (is_floor(y, draw_end))
			draw_floor(x, y, mlx->mapdata->floor_num, mlx);
		else
			draw_wall_texture(x, y, mlx);
		y++;
	}
}
