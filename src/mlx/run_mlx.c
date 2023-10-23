#include "include/cub3d.h"

void	run_mlx(t_map *mapdate)
{
	t_mlx	mlx;

	(void)mapdate;
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		exit_error("ERROR: cannot run mlx_init()");
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINSIZE_HEIGTH, WINSIZE_WIDTH, "cub3D");
	if (!mlx.mlx_win)
		exit_error("ERROR: cannot run mlx_new_window()");
	set_player(&mlx);
	set_wall_texture(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_raycast, &mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, &ft_press_key, &mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 2, ft_destroy, "press close button");
	mlx_loop(mlx.mlx_ptr);
}
