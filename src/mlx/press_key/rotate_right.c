/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:13:23 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:13:30 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_mlx *mlx)
{
	mlx->player_direct += 10 * (M_PI / 180);
	if (mlx->player_direct > 2 * M_PI)
		mlx->player_direct -= 2 * M_PI;
}
