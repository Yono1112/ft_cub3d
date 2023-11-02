/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:07:40 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/27 03:24:01 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_direction(t_mlx *mlx, char direction)
{
	if (direction == 'N')
		mlx->player_direct = NORTH;
	if (direction == 'S')
		mlx->player_direct = SOUTH;
	if (direction == 'E')
		mlx->player_direct = EAST;
	if (direction == 'W')
		mlx->player_direct = WEST;
}

void	set_player(t_mlx *mlx, char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				mlx->pos_x = (double)x + 0.5;
				mlx->pos_y = (double)y + 0.5;
				set_direction(mlx, map[y][x]);
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	exit_error(SET_PLAYER_ERROR, mlx->mapdata, mlx->mapdata->map);
}
