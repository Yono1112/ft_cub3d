#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h>

typedef struct s_mlx
{
	void	*init_ptr;
	void	*win;
}	t_mlx;

char	world_map[8][8] = 
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

int	key_press(int i, void *param)
{
	printf("%d\n", i);
	(void)param;
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			printf("%c", world_map[i][j]);
		printf("\n");
	}
	mlx.init_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.init_ptr, 640, 480, "cub3D");
	mlx_hook(mlx.win, 2, 0, &key_press, NULL);
	mlx_loop(mlx.init_ptr);
	return (0);
}
