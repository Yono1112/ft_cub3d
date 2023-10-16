#include "test_raycast.h"

void	set_draw_start_end(int wall_height, int *draw_start, int *draw_end)
{
	*draw_start = -1 * wall_height / 2 + WINSIZE_HEIGTH / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = wall_height / 2 + WINSIZE_HEIGTH / 2;
	if (*draw_end >= WINSIZE_HEIGTH)
		*draw_end = WINSIZE_HEIGTH - 1;
}

bool	is_ceiling(int y, int draw_start)
{
	return (y < draw_start);
}

bool	is_floor(int y, int draw_end)
{
	return (y > draw_end);
}

void	draw_ceiling(int x, int y, void *mlx_ptr, void *mlx_win)
{
	long	color_ceiling;

	color_ceiling = (255 * 65536) + (255 * 256) + 255;
	mlx_pixel_put(mlx_ptr, mlx_win, x, y, color_ceiling);
}

void	draw_floor(int x, int y, void *mlx_ptr, void *mlx_win)
{
	long	color_floor;

	color_floor = (255 * 65536) + (255 * 256) + 255;
	mlx_pixel_put(mlx_ptr, mlx_win, x, y, color_floor);
}

void	draw_wall_texture()
{
}

void	draw_wall_texture_ceiling_floor(t_mlx *mlx, size_t x)
{
	int		y;
	int		draw_start;
	int		draw_end;

	y = 0;
	mlx->wall_height = WINSIZE_HEIGTH / mlx->dist_to_wall;
	printf("mlx->wall_height: %d\n", mlx->wall_height);
	set_draw_start_end(mlx->wall_height, &draw_start, &draw_end);
	while (y < WINSIZE_HEIGTH)
	{
		if (is_ceiling(y, draw_start))
			draw_ceiling(x, y, mlx->mlx_ptr, mlx->mlx_win);
		else if (is_floor(y, draw_end))
			draw_floor(x, y, mlx->mlx_ptr, mlx->mlx_win);
		// else
		// 	draw_wall_texture();
		y++;
	}
}
