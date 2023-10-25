#include "cub3d.h"

void	free_map(char **map)
{
	size_t i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_mapdate(t_map *mapdate)
{
	size_t	i;

	i = 0;
	if (mapdate->map)
		free_map(mapdate->map);
	if (mapdate->no)
		free(mapdate->no);
	if (mapdate->ea)
		free(mapdate->ea);
	if (mapdate->so)
		free(mapdate->so);
	if (mapdate->we)
		free(mapdate->we);
	if (mapdate->floor)
		free(mapdate->floor);
	if (mapdate->ceiling)
		free(mapdate->ceiling);
	if (mapdate->ceiling_num_char[i])
	{
		i = 0;
		while (mapdate->ceiling_num_char[i])
		{
			free(mapdate->ceiling_num_char[i]);
			i++;
		}
	}
	if (mapdate->floor_num_char[i])
	{
		i = 0;
		while (mapdate->floor_num_char[i])
		{
			free(mapdate->floor_num_char[i]);
			i++;
		}
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("start print_map\n");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("finish print_map\n");
}

void	ft_init_mlx(t_mlx *mlx, t_map *mapdate)
{
	mlx->mapdata = mapdate;
	// printf("%s\n", mlx->mapdate->ea);
	// print_map(mlx->mapdata->map);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error(MLX_INIT_ERROR);
	mlx->mlx_win = mlx_new_window(
			mlx->mlx_ptr, WINSIZE_HEIGTH, WINSIZE_WIDTH, GAME_NAME);
	if (!mlx->mlx_win)
		error(MLX_WINDOW_ERROR);
	set_player(mlx, mlx->mapdata->map);
	printf("finish set_player\n");
	set_wall_texture(mlx, mlx->mapdata);
	// free_mapdate(mapdate);
}
