#include "cub3d.h"

void	run_mlx(t_map *mapdata)
{
	t_mlx	mlx;

	ft_init_mlx(&mlx, mapdata);
	mlx_loop_hook(mlx.mlx_ptr, ft_raycast, &mlx);
	mlx_hook(mlx.mlx_win, X_EVENT_KEY_PRESS, 1L << 0, ft_press_key, &mlx);
	mlx_hook(mlx.mlx_win, X_EVENT_DESTROY_NOTIFY,
		1L << 2, ft_destroy, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
