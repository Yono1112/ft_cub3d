/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumaohno <yumaohno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:58:35 by rnaka             #+#    #+#             */
/*   Updated: 2023/10/29 06:22:23 by rnaka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	skip_space(char **map, int *i, t_map *mapdata) //最初に文字が来る行を特定している
{
	int	j;

	while (map[*i])
	{
		j = 0;
		while (!ft_isprint(map[*i][j]) && map[*i][j])
			j++;
		if (ft_isprint(map[*i][j]))
			break ;
		(*i)++;
	}
	if (!map[*i])
		exit_error(NOT_ENOUGH_ARGUMENT_ERROR, mapdata, map);
}

void	check_map(char **map, int i)//checkではなくeditmap
{
	int	stock;
	int	strlen;
	char	*newline;
	size_t	maxlen;// 最長行

	maxlen = 0;
	//skip_space(map, &i); //check_textureでスペース飛ばしを行っているので必要ない,あっても問題ない
	stock = i;
	while (map[i])//最長行を探している
	{
		if (ft_strlen(map[i]) > maxlen)
			maxlen = ft_strlen(map[i]);
		i++;
	}
	i = stock;
	while (map[i])
	{
		newline = malloc(sizeof(char)*maxlen);
		newline[maxlen-1] = '\0';//NULL stoper
		strlen = ft_strlen(map[i]) - 1;
		ft_memcpy(newline, map[i], strlen);// strlen-1は'\n'分減らしているが、確認が必要
		free(map[i]);
		stock = strlen;
		while (stock < (int)maxlen - 1)
		{
			newline[stock] = ' ';
			stock++;
		}
		map[i] = newline;
		// printf("%s\n",map[i]);
		i++;
	}
	i = stock;
}

void	check_mapcontents(char **map, int i, t_map *mapdata)
{
	int	count_news;
	int	j;

	count_news = 0;
	skip_space(map, &i, mapdata);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
				//printf("%d    %d\n" , i, j);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' )
				exit_error(MAP_ARGUMENT_ERROR, mapdata, map);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S' )
			{
				if (count_news)
					exit_error(MAP_ARGUMENT_ERROR, mapdata, map);
				count_news++;
			}
			j++;
		}
		i++;
	}
	if (!count_news)
		exit_error(NUM_ARGUMENT_ERROR, mapdata, map);
}

void	check_hole(char **map, int i, int j, int border, t_map *mapdata)
{
	if ((!map[i + 1] && map[i][j] == '0') || map[i][j] == ' ' || map[i][j] == '\0' || (map[i][j] == '\0' && j == 0 ))
		exit_error(HOLE_MAP_ERROR, mapdata, map);
	if (j < 0 || i < border || !map[i] || map[i][j] == '\0' || map[i][j] == '1' || map[i][j] == '2')//すでに移動した箇所を2に置き換えている。"D"などにすべき
		 return ;
	if (map[i][j] == '0')
		map[i][j] = '2';
	check_hole(map, i + 1, j, border, mapdata);
	check_hole(map, i - 1, j, border, mapdata);
	check_hole(map, i, j + 1, border, mapdata);
	check_hole(map, i, j - 1, border, mapdata);
}

void	check_mapcollect(char **map, int i, t_map *mapdata)
{
	int	j;
	int	border;

	skip_space(map, &i, mapdata);
	border = i;
	while (map[i])//スタート位置探索
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
	check_hole(map, i, j, border, mapdata);
}

void	check_readable_texture(char **map, t_map *mapdata)
{
	int	fd;

//--------------------------------------------------------------------------------------------------------------
//	printf("openfd = %d vs %d\n", open(mapdata->no,O_RDONLY), open("./path_to_the_north_texture",O_RDONLY));
//	printf("%s vs %s\n",mapdata->no, "./path_to_the_north_texture");
//--------------------------------------------------------------------------------------------------------------
	fd = open(mapdata->no,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
	fd = open(mapdata->so,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
	fd = open(mapdata->ea,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
	fd = open(mapdata->we,O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_TEXTURE_ERROR, mapdata, map);
	close(fd);
}

bool	check_num_coma(char* str)
{
	int i;
	int commma_num;

	i = 0;
	commma_num = 0;
	while (str[i])
	{
//		printf("%c", str[i]);
		if (commma_num > 2 || (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != '\n') || (str[i] == ',' && !ft_isdigit(str[i + 1])))
			return(false);
		if (str[i] == '\n')
			str[i] = '\0';
		if (str[i] == ',' )
			commma_num++;
		i++;
	}
	if (commma_num < 2)
		return(false);
	return (true);
}

int	split_number(t_map *mapdata)
{
	char **array_ceiling;
	char **array_floor;
	int num_ceiling;
	int num_floor;
	int i;

	i = 0;
	array_floor = ft_split(mapdata->floor, ',');
	array_ceiling = ft_split(mapdata->ceiling, ',');
	while (array_ceiling[i] && array_floor[i])
	{
		num_ceiling = ft_atoi(array_ceiling[i]);
		num_floor = ft_atoi(array_floor[i]);
		if (num_ceiling > 255 || num_floor > 255)
			return(false);
		free(array_floor[i]);
		free(array_ceiling[i]);
		mapdata->floor_num[i] = num_floor;
		mapdata->ceiling_num[i] = num_ceiling;
		printf("floor = %d\n",mapdata->floor_num[i]);
		printf("ceiling = %d\n",mapdata->ceiling_num[i]);
		i++;
	}
	printf("texture num 設置完了\n");
	//free(array_floor);
	//free(array_ceiling);
	printf("free 完了num 置完了\n");
//------------------------------------------------------------
//	printf("\n");
//	for (int i = 0; i < 3; i++)
//	{
//		printf("floor %s, ceiling %s\n", mapdata->floor_num_char[i],mapdata->ceiling_num_char[i]);
//	}
//------------------------------------------------------------
	return(true);
}

void	check_floor_ceiling(char **map, t_map *mapdata)
{
	if (!check_num_coma(mapdata->floor) || !check_num_coma(mapdata->ceiling))
		exit_error(COMMA_ERROR, mapdata, map);
	if (!split_number(mapdata))
		exit_error(TEXTURE_BIG_ERROR, mapdata, map);
}

char**	creat_new_map(char **map, int i)
{
	int	j;
	int	stock;
	char	**newmap;

	// printf("start create_new_map\n");
	stock = i;
	while (map[stock])
		stock++;
	newmap = (char **)malloc(sizeof(char *) * (stock - i + 1));
	newmap[stock - i] = NULL;
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
	return (newmap);
}

bool	is_blankline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return true;
	while (line[i])
	{
		if (ft_isprint(line[i]))
			return false;
		i++;
	}
	return true;
}

void	check_single_map(char **map, int i, t_map *mapdata)
{
	while (map[i])
	{
		if (is_blankline(map[i]) && !is_blankline(map[i + 1]))
			exit_error(TOO_MANY_MAPS, mapdata, map);
		i++;
	}
}

void	check_mapfile(char **map, t_map *mapdata)
{
	int	i;

	i = check_texture(map, mapdata);
	check_single_map(map, i, mapdata);
	check_map(map, i);
	check_mapcontents(map, i, mapdata);
	check_mapcollect(map, i, mapdata);
	check_floor_ceiling(map, mapdata);
	check_readable_texture(map, mapdata);
	mapdata->map = creat_new_map(map, i);
	printf("namunamu\n");

//--------------------------------------------------------------------------------
//	for (int i = 0; i < 4; i++)
//		printf("%s\n",mapdata->map[i]);
//--------------------------------------------------------------------------------
}
