/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/08/19 11:07:26 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

char *check_direction(char *line, char *dir)
{
	int i = 0;

	while (!ft_isalpha(line[i]))
		i++;
	if (ft_strncmp(line + i, dir, ft_strlen(dir)))
		error(5);
	i += ft_strlen(dir);
	while (!ft_isalpha(line[i]))
		i++;
	return ft_strdup(line + i);
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

char	*cheack_ceiling_and_floor(char *line, char c)
{
	int i = 0;

	while (!ft_isalpha(line[i]))
		i++;
	if (line[i] != c)
		error(5);
	i++;
	while (!ft_isalnum(line[i]))
		i++;
	return ft_strdup(line + i);	
}

int	check_texture(char **map, t_map *mapdata)
{
	int	i;
	int	j;

	i = 0;
	skip_space(map, &i);
	mapdata->no = check_direction(map[i], "NO");
	skip_space(map, &i);
	mapdata->so = check_direction(map[i], "SO");
	skip_space(map, &i);
	mapdata->ea = check_direction(map[i], "EA");
	skip_space(map, &i);
	mapdata->we = check_direction(map[i], "WE");
	skip_space(map, &i);
	mapdata->floor = cheack_ceiling_and_floor(map[i], 'F');
	skip_space(map, &i);
	mapdata->ceiling = cheack_ceiling_and_floor(map[i], 'C');
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
			newline[stock] = 'a';
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
		i++;
	}
	if (!count_news)
		error(5);
}

void	check_hole(char **map, int i, int j, int border)
{
	if (j < 0 || i < border || !map[i] || map[i][j] == '\0' || map[i][j] == '1' || map[i][j] == '2')
		 return ;
	if (map[i][j] == ' ')
		error(5);
	if (map[i][j] == '0')
		map[i][j] = '2';
	check_hole(map, i + 1, j, border);
	check_hole(map, i - 1, j, border);
	check_hole(map, i, j + 1, border);
	check_hole(map, i, j - 1, border);
}

void	check_mapcollect(char **map, t_map *mapdata, int i)
{
	int	j;
	int	border;

	skip_space(map, &i);
	border = i;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
				break ;
			j++;
		}
		if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
			break ;
		i++;
	}
	check_hole(map, i, j, border);

}

void	check_mapfile(char **map, t_map *mapdata)
{
	int	i;
	int	j;
	int	stock;
	int	start;
	char	**newmap;

	j = 0;
	i = check_texture(map, mapdata);
	i++;
	check_map(map, mapdata, i);
	check_mapcontents(map, mapdata, i);
	check_mapcollect(map, mapdata, i);
	stock = i;
	while (map[stock])
		stock++;
	newmap = (char **)malloc(sizeof(char *) * (stock - i + 1));
	newmap[i - stock] = NULL;
	stock = i;
	i = 0;
	while (map[i + stock])
	{
		j = 0;
		while (map[i + stock][j])
		{
			if (map[i + stock][j] == ' ')
				map[i + stock][j] = '1';
			else if(map[i + stock][j] == '2')
				map[i + stock][j] = '0';
			j++;
		}
		newmap[i] = ft_strdup(map[i + stock]);
		i++;
	}
	mapdata->map = newmap;
}

