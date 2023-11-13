/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:39:47 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/07 16:27:44 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_direction(double direct_flag, t_mlx *mlx, int side)
{
	if (direct_flag == NORTH)
		return (side == SIDE_Y && mlx->ray_dir_y < 0);
	else if (direct_flag == SOUTH)
		return (side == SIDE_Y && mlx->ray_dir_y >= 0);
	else if (direct_flag == EAST)
		return (side == SIDE_X && mlx->ray_dir_x >= 0);
	else if (direct_flag == WEST)
		return (side == SIDE_X && mlx->ray_dir_x < 0);
	return (false);
}

static double	calc_wall_x(t_mlx *mlx)
{
	double	wall_x;

	if (mlx->side == SIDE_X)
		wall_x = mlx->pos_y + mlx->dist_to_wall * mlx->ray_dir_y;
	else
		wall_x = mlx->pos_x + mlx->dist_to_wall * mlx->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

static double	calc_tex_x(t_mlx *mlx, int side, double wall_x)
{
	double	tex_x;

	tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (is_direction(SOUTH, mlx, side))
		tex_x = TEX_WIDTH - tex_x - 1;
	else if (is_direction(WEST, mlx, side))
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

static int	set_index_texture(t_mlx *mlx, int side)
{
	if (is_direction(NORTH, mlx, side))
		return (SOUTH_TEX);
	if (is_direction(SOUTH, mlx, side))
		return (NORTH_TEX);
	if (is_direction(WEST, mlx, side))
		return (EAST_TEX);
	if (is_direction(EAST, mlx, side))
		return (WEST_TEX);
	return (-1);
}

void	draw_wall_texture(int x, int y, t_mlx *mlx)
{
	long	index_texture;
	double	wall_x;
	int		tex_x;
	int		tex_y;

	wall_x = calc_wall_x(mlx);
	tex_x = calc_tex_x(mlx, mlx->side, wall_x);
	tex_y = (int)mlx->wall_y % TEX_HEIGHT;
	mlx->wall_y += mlx->step;
	index_texture = set_index_texture(mlx, mlx->side);
	if (index_texture < 0)
		exit_error(INDEX_TEXTURE_ERROR, mlx->mapdata, mlx->mapdata->map);
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y,
		*(int *)(mlx->wall_texture[index_texture].deta_addr
			+ tex_y * mlx->wall_texture[index_texture].size_line
			+ tex_x * (mlx->wall_texture[index_texture].bits_per_pixel / 8)));
}
