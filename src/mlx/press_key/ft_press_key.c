/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:08:46 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/05 17:17:12 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_press_key(int key_num, t_mlx *mlx)
{
	if (key_num == KEY_ESC)
		ft_destroy(mlx);
	if (key_num == KEY_W)
		mlx->key_w = true;
	else if (key_num == KEY_S)
		mlx->key_s = true;
	else if (key_num == KEY_A)
		mlx->key_a = true;
	else if (key_num == KEY_D)
		mlx->key_d = true;
	else if (key_num == KEY_ARROW_LEFT)
		mlx->key_arrow_left = true;
	else if (key_num == KEY_ARROW_RIGHT)
		mlx->key_arrow_right = true;
	return (0);
}
