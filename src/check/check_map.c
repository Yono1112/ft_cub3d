#include "cub3d.h"

void	check_map(char **map, int i)//checkではなくeditmap
{
	int	stock;
	int	strlen;
	char	*newline;
	size_t	maxlen;

	maxlen = 0;
	stock = i;
	while (map[i])
	{
		if (ft_strlen(map[i]) > maxlen)
			maxlen = ft_strlen(map[i]);
		i++;
	}
	i = stock;
	while (map[i])
	{
		newline = malloc(sizeof(char)*maxlen);
		if (!newline)
			exit_error(MALLOC_ERROR, NULL, NULL);
		newline[maxlen-1] = '\0';
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

