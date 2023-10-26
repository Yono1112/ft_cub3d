/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:08:46 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:17:18 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_press_key(int key_num, t_mlx *mlx)
{
	if (key_num == KEY_ESC)
		ft_destroy(mlx);
	else if (key_num == KEY_W)
		move_forward(mlx);
	else if (key_num == KEY_S)
		move_back(mlx);
	else if (key_num == KEY_A)
		move_left(mlx);
	else if (key_num == KEY_D)
		move_right(mlx);
	else if (key_num == KEY_ARROW_LEFT)
		rotate_left(mlx);
	else if (key_num == KEY_ARROW_RIGHT)
		rotate_right(mlx);
	return (0);
}
