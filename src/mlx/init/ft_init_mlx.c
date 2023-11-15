/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:07:25 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/16 01:15:24 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_key(t_mlx *mlx)
{
	mlx->key_w = false;
	mlx->key_s = false;
	mlx->key_a = false;
	mlx->key_d = false;
	mlx->key_arrow_left = false;
	mlx->key_arrow_right = false;
}

void	ft_init_mlx(t_mlx *mlx, t_map *mapdata)
{
	mlx->mapdata = mapdata;
	init_mlx_key(mlx);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		exit_error(MLX_INIT_ERROR, mlx->mapdata, mlx->mapdata->map);
	set_player(mlx, mlx->mapdata->map);
	set_wall_texture(mlx, mlx->mapdata);
	mlx->mlx_win = mlx_new_window(
			mlx->mlx_ptr, WINSIZE_WIDTH, WINSIZE_HEIGTH, GAME_NAME);
	if (!mlx->mlx_win)
		exit_error(MLX_WINDOW_ERROR, mlx->mapdata, mlx->mapdata->map);
}
