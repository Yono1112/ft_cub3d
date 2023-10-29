/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:42 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/29 16:42:31 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_destroy(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	while (i < 4)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall_texture[i++].img_ptr);
	free_data(mlx->mapdata, mlx->mapdata->map);
	write(STDOUT_FILENO, DESTROY_PREFIX, ft_strlen(DESTROY_PREFIX));
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}
