/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:38:03 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/31 20:33:57 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	max_len(char **map, int i)
{
	size_t	maxlen;

	maxlen = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > maxlen)
			maxlen = ft_strlen(map[i]);
		i++;
	}
	return (maxlen);
}

void	check_map(char **map, int i)
{
	int		stock;
	int		strlen;
	char	*newline;
	size_t	maxlen;

	maxlen = max_len(map, i);
	while (map[i])
	{
		newline = malloc(sizeof(char) * maxlen);
		if (!newline)
			exit_error(MALLOC_ERROR, NULL, NULL);
		newline[maxlen - 1] = '\0';
		strlen = ft_strlen(map[i]) - 1;
		ft_memcpy(newline, map[i], strlen);
		free(map[i]);
		stock = strlen;
		while (stock < (int)maxlen - 1)
		{
			newline[stock] = ' ';
			stock++;
		}
		map[i] = newline;
		i++;
	}
	i = stock;
}
