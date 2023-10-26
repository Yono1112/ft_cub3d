/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:09:06 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:24:58 by yumaohno         ###   ########.fr       */
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
		draw_wall_texture_ceiling_floor(mlx, x);
		x++;
	}
	return (0);
}
