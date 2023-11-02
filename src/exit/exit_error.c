/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:29:36 by yumaohno          #+#    #+#             */
/*   Updated: 2023/10/29 16:29:37 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(char *str, t_map *mapdata, char **map)
{
	if (mapdata)
		free_data(mapdata, map);
	write(STDERR_FILENO, ERROR_PREFIX, ft_strlen(ERROR_PREFIX));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}
