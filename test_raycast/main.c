#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h>

int	world_map[8][8] = 
{
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

int	key_press(int i, void *param)
{
	printf("%d\n", i);
	(void)param;
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;

	for (int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
			printf("%d", world_map[i][j]);
		printf("\n");
	}
	mlx_ptr = mlx_init();
	printf("%p\n", mlx_ptr);
	mlx_win = mlx_new_window(mlx_ptr, 640, 480, "cub3D");
	mlx_hook(mlx_win, 2, 0, &key_press, NULL);
	mlx_loop(mlx_ptr);
	// printf("hello\n");
	return (0);
}
