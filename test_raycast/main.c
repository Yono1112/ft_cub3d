#include "test_raycast.h"

char	world_map[mapheight][mapwidth] = 
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
	mlx.init_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.init_ptr, 640, 480, "cub3D");
	set_player(&mlx);
	// printf("%f, %f\n", mlx.pos_x, mlx.pos_y);
	// printf("%d, %d\n", mlx.map_x, mlx.map_y);
	mlx_hook(mlx.win, 2, 0, &key_press, NULL);
	mlx_loop(mlx.init_ptr);
	return (0);
}
