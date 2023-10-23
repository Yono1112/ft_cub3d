#include "cub3d.h"

void	ft_init_mlx(t_mlx *mlx, t_map *mapdate)
{
	mlx->mapdate = mapdate;
	printf("%s\n", mlx->mapdate->ea);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		exit_error("ERROR: cannot run mlx_init()");
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WINSIZE_HEIGTH, WINSIZE_WIDTH, "cub3D");
	if (!mlx->mlx_win)
		exit_error("ERROR: cannot run mlx_new_window()");
	set_player(mlx, mlx->mapdate->map);
	// set_wall_texture(mlx);
}
