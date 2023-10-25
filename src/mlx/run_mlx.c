#include "cub3d.h"

void	run_mlx(t_map *mapdate)
{
	t_mlx	mlx;

	ft_init_mlx(&mlx, mapdate);
	mlx_loop_hook(mlx.mlx_ptr, ft_raycast, &mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, &ft_press_key, &mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 2, ft_destroy, "press close button");
	mlx_loop(mlx.mlx_ptr);
}
