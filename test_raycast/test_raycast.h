#ifndef TEST_RAYCAST_H
# define TEST_RAYCAST_H

# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"

# define MAP_WIDTH 16
# define MAP_HEIGHT 16
# define WINSIZE_WIDTH 800
# define WINSIZE_HEIGTH 800
# define SOUTH (M_PI / 180) * 90
# define NORTH (M_PI / 180) * 270
# define EAST (M_PI / 180) * 0
# define WEST (M_PI / 180) * 180
# define FOV (M_PI / 180) * 60
# define SIDE_X 0
# define SIDE_Y 1
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define MOVE_SPEED 0.3
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NORTH_TEX 0
# define SOUTH_TEX 1
# define EAST_TEX 2
# define WEST_TEX 3
# define MOVE_FORWARD 0
# define MOVE_BACK 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3

typedef struct s_img
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
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
	double	wall_height;
	// texture
	t_img	wall_texture[4];
	double	step;
	double	tex_pos;
}	t_mlx;

char	world_map[MAP_HEIGHT][MAP_WIDTH];
char	*wall_texture[4];

void	set_player(t_mlx *mlx);
void	exit_error(char *str);
int		ft_raycast(t_mlx *mlx);
void	calc_dist_to_wall(t_mlx *mlx);
void	draw_wall_texture_ceiling_floor(t_mlx *mlx, size_t x);
void	set_wall_texture(t_mlx *mlx);
int		ft_destroy(char *str, t_mlx *mlx);
int		ft_press_key(int i, t_mlx *mlx);
void	init_raycast_value(t_mlx *mlx, size_t x);

#endif