/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:35:00 by yumaohno          #+#    #+#             */
/*   Updated: 2023/11/02 20:20:00 by yumaohno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	mapdata;

	check_error((const int)argc, (const char **)argv, &mapdata);
	print_map(mapdata.map);
	run_mlx(&mapdata);
	exit(EXIT_SUCCESS);
}

// __attribute__((destructor))
// static void	destructor(void)
// {
// 	system("leaks -q cub3D");
// }
