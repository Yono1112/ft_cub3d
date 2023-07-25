/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/07/26 03:06:29 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char	*check_south(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "SO", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_east(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "EA", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_west(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "WE", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_north(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "NO", 2))
		error(5);
	i += 2;
	while (!ft_isalpha(line[i]))
		i++;
	return (ft_strdup(line + i));
}

void	skip_space(char **map, int *i)
{
	int	j;

	while (map[*i])
	{
		j = 0;
		while (!ft_isalnum(map[*i][j]) && map[*i][j])
			j++;
		if (ft_isalnum(map[*i][j]))
			break ;
		(*i)++;
	}
	if (!map[*i])
		error(5);
}

char	*check_ceiling(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "C", 1))
		error(5);
	i += 1;
	while (!ft_isalnum(line[i]))
		i++;
	return (ft_strdup(line + i));
}

char	*check_floor(char *line)
{
	int	i;

	i = 0;
	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, "F", 1))
		error(5);
	i += 1;
	while (!ft_isalnum(line[i]))
		i++;
	return (ft_strdup(line + i));
}

int	check_texture(char **map, t_map *mapdata)
{
	int	i;
	int	j;

	i = 0;
	skip_space(map, &i);
	mapdata->no = check_north(map[i]);
	i++;
	skip_space(map, &i);
	mapdata->so = check_south(map[i]);
	i++;
	skip_space(map, &i);
	mapdata->ea = check_east(map[i]);
	i++;
	skip_space(map, &i);
	mapdata->we = check_west(map[i]);
	i++;
	skip_space(map, &i);
	mapdata->floor = check_floor(map[i]);
	i++;
	skip_space(map, &i);
	mapdata->ceiling = check_ceiling(map[i]);
	skip_space(map, &i);
	return i;
}

void	check_map(char **map, t_map *mapdata, int i)
{
	int	stock;
	int	maxlen;
	int	strlen;
	char	*newline;

	maxlen = 0;
	skip_space(map, &i);
	stock = i;
	while (map[i])
	{
		if (ft_strlen(map[i])>maxlen)
			maxlen = ft_strlen(map[i]);
		i++;
	}
	i = stock;
	while (map[i])
	{
		newline = malloc(sizeof(char)*maxlen);
		newline[maxlen-1] = '\0';
		strlen = ft_strlen(map[i])-1;
		ft_memcpy(newline, map[i], strlen);// strlen-1は'\n'分減らしているが、確認が必要
		free(map[i]);
		stock = strlen;
		while (stock < maxlen-1)
		{
			newline[stock] = ' ';
			stock++;
		}
		map[i] = newline;
		i++;
	}
	i = stock;
}
void	check_mapcontents(char **map, t_map *mapdata, int i)
{
	int	count_news;
	int	j;

	count_news = 0;
	skip_space(map, &i);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c",map[i][j]);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' )
				error(5);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
			{
				if (count_news)
					error(5);
				count_news++;
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

void	check_mapfile(char **map, t_map *mapdata)
{
	int	i;

	i = check_texture(map, mapdata);
	i++;
	check_map(map, mapdata, i);
	check_mapcontents(map, mapdata, i);
}
