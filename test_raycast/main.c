#include "test_raycast.h"

char	world_map[MAP_HEIGHT][MAP_WIDTH] = 
{
	{'1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', 'N', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1'},
};

void	print_world_map(void)
{
	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			printf("%c", world_map[i][j]);
		printf("\n");
	}
}

int	key_press(int i, void *param)
{
	printf("%d\n", i);
	(void)param;
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	print_world_map();
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		exit_error("ERROR: cannot run mlx_init()");
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINSIZE_HEIGTH, WINSIZE_WIDTH, "cub3D");
	if (!mlx.mlx_win)
		exit_error("ERROR: cannot run mlx_new_window()");
	mlx.fov = FOV;
	set_player(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_raycast, &mlx);
	mlx_hook(mlx.mlx_win, 2, 0, &key_press, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
