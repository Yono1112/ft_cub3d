/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <rnaka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:56:13 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/31 20:52:48 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_extencion(const char *argv)
{
	char	*ber;
	int		i;
	int		j;

	i = 0;
	ber = ".cub\0";
	while (argv[i])
	{
		j = 0;
		while (argv[i] == ber[j] && ber[j])
		{
			j++;
			i++;
		}
		if (ber[j] == '\0' && argv[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	file_name(const int argc, const char *argv[])
{
	if (argc != 2)
		exit_error(ARGUMENT_ERROR, NULL, NULL);
	else if (check_extencion(argv[1]))
		exit_error(FILENAME_ERROR, NULL, NULL);
	return ;
}
