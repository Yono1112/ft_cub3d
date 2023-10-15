#ifndef TEST_RAYCAST_H
# define TEST_RAYCAST_H

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"

# define MAP_WIDTH 8
# define MAP_HEIGHT 8
# define WINSIZE_WIDTH 640
# define WINSIZE_HEIGTH 480
# define SOUTH (M_PI / 180) * 90
# define NORTH (M_PI / 180) * 270
# define EAST (M_PI / 180) * 0
# define WEST (M_PI / 180) * 180
# define FOV (M_PI / 180) * 60
# define SIDE_X 0
# define SIDE_Y 1

typedef struct s_img
{
	void	*img_ptr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;
	char	*deta_addr;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	player_direct;
	double	ray_direct;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist_to_wall;
	int		step_x;
	int		step_y;
	int		side;
	// texture
	t_img	wall_texure[4];
}	t_mlx;

char	world_map[MAP_HEIGHT][MAP_WIDTH];
void	set_player(t_mlx *mlx);
void	exit_error(char *str);
int		ft_raycast(t_mlx *mlx);
void	calc_dist_to_wall(t_mlx *mlx);
void	draw_wall_texture(t_mlx *mlx, size_t x);
void	set_wall_texture(t_mlx *mlx);

#endif