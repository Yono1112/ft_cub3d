#include "cub3d.h"

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

void	ft_init_mlx(t_mlx *mlx, t_map *mapdata)
{
	mlx->mapdata = mapdata;
	// printf("%s\n", mlx->mapdate->ea);
	// print_map(mlx->mapdata->map);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		exit_error(MLX_INIT_ERROR, mlx->mapdata, mlx->mapdata->map);
	mlx->mlx_win = mlx_new_window(
			mlx->mlx_ptr, WINSIZE_WIDTH, WINSIZE_HEIGTH, GAME_NAME);
	if (!mlx->mlx_win)
		exit_error(MLX_WINDOW_ERROR, mlx->mapdata, mlx->mapdata->map);
	set_player(mlx, mlx->mapdata->map);
	printf("finish set_player\n");
	set_wall_texture(mlx, mlx->mapdata);
	// free_mapdate(mapdate);
}
