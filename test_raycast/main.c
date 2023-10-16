#include "test_raycast.h"

char	world_map[MAP_HEIGHT][MAP_WIDTH] = 
{
	{'1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', 'N', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1'},
};

char	*north_texture = "./wall_texture/";
char	*south_texture = "./wall_texture/";
char	*east_texture = "./wall_texture/";
char	*west_texture = "./wall_texture/";

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

// int	ft_destroy(t_mlx *mlx)
// {
// 	(void)mlx;
// 	printf("FINISH: click button\n");
// 	exit(0);
// }

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
	set_player(&mlx);
	// set_wall_texture(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, ft_raycast, &mlx);
	// mlx_hook(mlx.mlx_win, 2, 1L << 0, &key_press, &mlx);
	// mlx_hook(mlx.mlx_win, 17, 1L << 2, ft_destroy, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
