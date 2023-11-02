/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:13:04 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 03:15:15 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_mlx *mlx)
{
	mlx->player_direct -= 10 * (M_PI / 180);
	if (mlx->player_direct < 0)
		mlx->player_direct += 2 * M_PI;
}
