#include "test_raycast.h"

void	set_draw_start_end(double wall_height, double *draw_start, double *draw_end)
{
	*draw_start = -1 * wall_height / 2.0 + (double)WINSIZE_HEIGTH / 2.0;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = wall_height / 2.0 + (double)WINSIZE_HEIGTH / 2.0;
	if (*draw_end >= WINSIZE_HEIGTH)
		*draw_end = WINSIZE_HEIGTH - 1;
}

bool	is_ceiling(int y, double draw_start)
{
	return (y < draw_start);
}

bool	is_floor(int y, double draw_end)
{
	return (y > draw_end);
}

void	draw_ceiling(int x, int y, void *mlx_ptr, void *mlx_win)
{
	long	color_ceiling;

	color_ceiling = (0 * 65536) + (0 * 256) + 0;
	mlx_pixel_put(mlx_ptr, mlx_win, x, y, color_ceiling);
}

void	draw_floor(int x, int y, void *mlx_ptr, void *mlx_win)
{
	long	color_floor;

	color_floor = (0 * 65536) + (0 * 256) + 0;
	mlx_pixel_put(mlx_ptr, mlx_win, x, y, color_floor);
}

void	calc_wall_x(double *wall_x, t_mlx *mlx)
{
	if (mlx->side == SIDE_X)
		*wall_x = mlx->pos_y + mlx->dist_to_wall * mlx->ray_dir_y;
	else
		*wall_x = mlx->pos_x + mlx->dist_to_wall * mlx->ray_dir_x;
	*wall_x -= floor(*wall_x);
}

void	calc_tex_x(int *tex_x, t_mlx *mlx, double wall_x)
{
	*tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (mlx->side == SIDE_Y && mlx->ray_dir_y >= 0)
		*tex_x = TEX_WIDTH - *tex_x - 1;
	else if (mlx->side == SIDE_X && mlx->ray_dir_x < 0)
		*tex_x = TEX_WIDTH - *tex_x - 1;
}

int		set_index_texture(t_mlx *mlx)
{
	if ((int)mlx->side == SIDE_Y
		&& sin(mlx->ray_direct) >= 0) //south
		return (NORTH_TEX);
		// color_wall_texture = (255 * 65536) + (0 * 256) + 0;
	else if ((int)mlx->side == SIDE_Y
		&& sin(mlx->ray_direct) < 0) // north
		return (SOUTH_TEX);
		// color_wall_texture = (0 * 65536) + (255 * 256) + 0;
	else if ((int)mlx->side == SIDE_X
		&& cos(mlx->ray_direct) >= 0) //east
		return (WEST_TEX);
		// color_wall_texture = (0 * 65536) + (0 * 256) + 255;
	else if ((int)mlx->side == SIDE_X
		&& cos(mlx->ray_direct) < 0) //west
		return (EAST_TEX);
	return (-1);
}

void	draw_wall_texture(int x, int y, t_mlx *mlx)
{
	long	index_texture;
	double	wall_x;
	int		tex_x;
	int		tex_y;

	calc_wall_x(&wall_x, mlx);
	calc_tex_x(&tex_x, mlx, wall_x);
	tex_y = (int)mlx->tex_pos & (TEX_HEIGHT - 1);
	mlx->tex_pos += mlx->step;
	index_texture = set_index_texture(mlx);
	// index_texture = 0;
	if (index_texture < 0)
		exit_error("ERROR: cannot set index_texture in draw_wall_texture()\n");
	// if ((int)mlx->side == SIDE_Y
	// 	&& sin(mlx->ray_direct) >= 0) //south
	// 	index_texture = (255 * 65536) + (0 * 256) + 0;
	// else if ((int)mlx->side == SIDE_Y
	// 	&& sin(mlx->ray_direct) < 0) // north
	// 	index_texture = (0 * 65536) + (255 * 256) + 0;
	// else if ((int)mlx->side == SIDE_X
	// 	&& cos(mlx->ray_direct) >= 0) //east
	// 	index_texture = (0 * 65536) + (0 * 256) + 255;
	// else if ((int)mlx->side == SIDE_X
	// 	&& cos(mlx->ray_direct) < 0) //west
	// 	index_texture = (255 * 65536) + (255 * 256) + 0;
	// printf("mlx->wall_texture: %s\n", wall_texture[index_texture]);
	// mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y, index_texture);
	mlx_pixel_put(mlx->mlx_ptr, mlx->mlx_win, x, y,
		*(int *)(mlx->wall_texture[index_texture].deta_addr
			+ tex_y * mlx->wall_texture[index_texture].size_line
			+ tex_x * (mlx->wall_texture[index_texture].bits_per_pixel / 8)));
}

void	draw_wall_texture_ceiling_floor(t_mlx *mlx, size_t x)
{
	int		y;
	double	draw_start;
	double	draw_end;

	y = 0;
	mlx->wall_height = WINSIZE_HEIGTH / mlx->dist_to_wall;
	// printf("mlx->wall_height: %f\n", mlx->wall_height);
	set_draw_start_end(mlx->wall_height, &draw_start, &draw_end);
	mlx->step = 1.0 * TEX_HEIGHT / mlx->wall_height;
	mlx->tex_pos = (draw_start - WINSIZE_HEIGTH / 2 + mlx->wall_height / 2)
		* mlx->step;
	while (y < WINSIZE_HEIGTH)
	{
		if (is_ceiling(y, draw_start))
			draw_ceiling(x, y, mlx->mlx_ptr, mlx->mlx_win);
		else if (is_floor(y, draw_end))
			draw_floor(x, y, mlx->mlx_ptr, mlx->mlx_win);
		else
			draw_wall_texture(x, y, mlx);
		y++;
	}
}
