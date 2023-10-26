/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:07:57 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:08:36 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_img_ptr(t_mlx *mlx, t_map *mapdata)
{
	int		height;
	int		width;

	height = WINSIZE_HEIGTH;
	width = WINSIZE_WIDTH;
	mlx->wall_texture[0].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->no, &height, &width);
	mlx->wall_texture[1].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->so, &height, &width);
	mlx->wall_texture[2].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->ea, &height, &width);
	mlx->wall_texture[3].img_ptr
		= mlx_xpm_file_to_image(mlx->mlx_ptr, mapdata->we, &height, &width);
	if (!mlx->wall_texture[0].img_ptr || !mlx->wall_texture[1].img_ptr
		|| !mlx->wall_texture[2].img_ptr || !mlx->wall_texture[3].img_ptr)
		exit_error(IMG_PTR_ERROR, mapdata, mapdata->map);
}

void	set_deta_addr(t_mlx *mlx)
{
	mlx->wall_texture[0].deta_addr = mlx_get_data_addr(
			mlx->wall_texture[0].img_ptr, &mlx->wall_texture[0].bits_per_pixel,
			&mlx->wall_texture[0].size_line, &mlx->wall_texture[0].endian);
	mlx->wall_texture[1].deta_addr = mlx_get_data_addr(
			mlx->wall_texture[1].img_ptr, &mlx->wall_texture[1].bits_per_pixel,
			&mlx->wall_texture[1].size_line, &mlx->wall_texture[1].endian);
	mlx->wall_texture[2].deta_addr = mlx_get_data_addr(
			mlx->wall_texture[2].img_ptr, &mlx->wall_texture[2].bits_per_pixel,
			&mlx->wall_texture[2].size_line, &mlx->wall_texture[2].endian);
	mlx->wall_texture[3].deta_addr = mlx_get_data_addr(
			mlx->wall_texture[3].img_ptr, &mlx->wall_texture[3].bits_per_pixel,
			&mlx->wall_texture[3].size_line, &mlx->wall_texture[3].endian);
	if (!mlx->wall_texture[0].deta_addr || !mlx->wall_texture[1].deta_addr
		|| !mlx->wall_texture[2].deta_addr || !mlx->wall_texture[3].deta_addr)
		exit_error(DETA_ADDR_ERROR, mlx->mapdata, mlx->mapdata->map);
}

void	set_wall_texture(t_mlx *mlx, t_map *mapdata)
{
	printf("start set_wall_texture\n");
	set_img_ptr(mlx, mapdata);
	set_deta_addr(mlx);
	printf("finish set_wall_texture\n");
}
