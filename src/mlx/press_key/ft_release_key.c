/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_release_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:26:31 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/05 17:28:13 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_release_key(int key_num, t_mlx *mlx)
{
	if (key_num == KEY_W)
		mlx->key_w = false;
	else if (key_num == KEY_S)
		mlx->key_s = false;
	else if (key_num == KEY_A)
		mlx->key_a = false;
	else if (key_num == KEY_D)
		mlx->key_d = false;
	else if (key_num == KEY_ARROW_LEFT)
		mlx->key_arrow_left = false;
	else if (key_num == KEY_ARROW_RIGHT)
		mlx->key_arrow_right = false;
	return (0);
}
