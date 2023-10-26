/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:09:06 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:21:09 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_raycast(t_mlx *mlx)
{
	size_t	x;

	x = 0;
	while (x < WINSIZE_WIDTH)
	{
		init_raycast_value(mlx, x);
		// printf("%ld: %f(%f°), %f(%f°)\n", x, mlx->player_direct, mlx->player_direct * (180 / M_PI), mlx->ray_direct, mlx->ray_direct * (180 / M_PI));
		// printf("dist_to_wall:%f(%f°)\n", mlx->dist_to_wall, mlx->ray_direct * (180 / M_PI));
		draw_wall_texture_ceiling_floor(mlx, x);
		x++;
	}
	return (0);
}
