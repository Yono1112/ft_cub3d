/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:07:18 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/05 17:42:54 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_mlx(t_map *mapdata)
{
	t_mlx	mlx;

	ft_init_mlx(&mlx, mapdata);
	mlx_loop_hook(mlx.mlx_ptr, ft_raycast, &mlx);
	mlx_hook(mlx.mlx_win, X_EVENT_KEY_PRESS, 1L << 0, ft_press_key, &mlx);
	mlx_hook(mlx.mlx_win, X_EVENT_KEY_RELEASE, 1L << 1, ft_release_key, &mlx);
	mlx_hook(mlx.mlx_win, X_EVENT_DESTROY_NOTIFY,
		1L << 2, ft_destroy, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
