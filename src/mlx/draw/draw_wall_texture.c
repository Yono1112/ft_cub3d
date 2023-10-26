/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:39:47 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:40:04 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_wall_x(double *wall_x, t_mlx *mlx)
{
	if (mlx->side == SIDE_X)
		*wall_x = mlx->pos_y + mlx->dist_to_wall * mlx->ray_dir_y;
	else
		*wall_x = mlx->pos_x + mlx->dist_to_wall * mlx->ray_dir_x;
	*wall_x -= floor(*wall_x);
}

void	calc_tex_x(int *tex_x, t_mlx *mlx, double wall_x)
{
	*tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (mlx->side == SIDE_Y && mlx->ray_dir_y >= 0)
		*tex_x = TEX_WIDTH - *tex_x - 1;
	else if (mlx->side == SIDE_X && mlx->ray_dir_x < 0)
		*tex_x = TEX_WIDTH - *tex_x - 1;
}

int	set_index_texture(t_mlx *mlx)
{
	if ((int)mlx->side == SIDE_Y
		&& sin(mlx->ray_direct) >= 0) //south
		return (NORTH_TEX);
	else if ((int)mlx->side == SIDE_Y
		&& sin(mlx->ray_direct) < 0) // north
		return (SOUTH_TEX);
	else if ((int)mlx->side == SIDE_X
		&& cos(mlx->ray_direct) >= 0) //east
		return (WEST_TEX);
	else if ((int)mlx->side == SIDE_X
		&& cos(mlx->ray_direct) < 0) //west
		return (EAST_TEX);
	return (-1);
}

void	draw_wall_texture(int x, int y, t_mlx *mlx)
{
	long	index_texture;
	double	wall_x;
	int		tex_x;
	int		tex_y;

	calc_wall_x(&wall_x, mlx);
	calc_tex_x(&tex_x, mlx, wall_x);
	tex_y = (int)mlx->tex_pos & (TEX_HEIGHT - 1);
	mlx->tex_pos += mlx->step;
	index_texture = set_index_texture(mlx);
	if (index_texture < 0)
		exit_error(INDEX_TEXTURE_ERROR, mlx->mapdata, mlx->mapdata->map);
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y,
		*(int *)(mlx->wall_texture[index_texture].deta_addr
			+ tex_y * mlx->wall_texture[index_texture].size_line
			+ tex_x * (mlx->wall_texture[index_texture].bits_per_pixel / 8)));
}
