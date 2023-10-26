/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_press_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:08:46 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 02:13:21 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_press_key(int key_num, t_mlx *mlx)
{
	printf("%d\n", key_num);
	if (key_num == KEY_ESC)
		ft_destroy(mlx);
	else if (key_num == KEY_W)
	{
		printf("press W key\n");
		move_forward(mlx);
		// exit(0);
	}
	else if (key_num == KEY_S)
	{
		printf("press S key\n");
		move_back(mlx);
	}
	else if (key_num == KEY_A)
	{
		printf("press A key\n");
		move_left(mlx);
	}
	else if (key_num == KEY_D)
	{
		printf("press D key\n");
		move_right(mlx);
	}
	else if (key_num == KEY_ARROW_LEFT)
	{
		printf("press KEY_ARROw_LEFT key\n");
		rotate_left(mlx);
	}
	else if (key_num == KEY_ARROW_RIGHT)
	{
		printf("press KEY_ARROW_RIGHT key\n");
		rotate_right(mlx);
	}
	// exit(0);
	return (0);
}
