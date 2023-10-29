/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:07:57 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/29 17:00:26 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_img_ptr(t_mlx *mlx, t_map *mapdata)
{
	int		height;
	int		width;

	height = WINSIZE_HEIGTH;
	width = WINSIZE_WIDTH;
	mlx->wall_texture[SOUTH_TEX].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->so, &height, &width);
	mlx->wall_texture[NORTH_TEX].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->no, &height, &width);
	mlx->wall_texture[WEST_TEX].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->we, &height, &width);
	mlx->wall_texture[EAST_TEX].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->ea, &height, &width);
	if (!mlx->wall_texture[0].img_ptr || !mlx->wall_texture[1].img_ptr
		|| !mlx->wall_texture[2].img_ptr || !mlx->wall_texture[3].img_ptr)
		exit_error(IMG_PTR_ERROR, mapdata, mapdata->map);
}

static void	set_deta_addr(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx->wall_texture[i].deta_addr = mlx_get_data_addr(
				mlx->wall_texture[i].img_ptr,
				&mlx->wall_texture[i].bits_per_pixel,
				&mlx->wall_texture[i].size_line,
				&mlx->wall_texture[i].endian);
		if (!mlx->wall_texture[i].deta_addr)
			exit_error(DETA_ADDR_ERROR, mlx->mapdata, mlx->mapdata->map);
		i++;
	}
}

void	set_wall_texture(t_mlx *mlx, t_map *mapdata)
{
	set_img_ptr(mlx, mapdata);
	set_deta_addr(mlx);
}
