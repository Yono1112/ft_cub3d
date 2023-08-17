#ifndef TEST_RAYCAST_H
#define TEST_RAYCAST_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../minilibx_opengl_20191021/mlx.h"

#define mapwidth 8
#define mapheight 8
#define pi 3.14592
#define SOUTH (pi / 180) * 90
#define NORTH (pi / 180) * 180
#define EAST (pi / 180) * 0
#define WEST (pi / 180) * 180

typedef struct s_mlx
{
	void	*init_ptr;
	void	*win;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	direction;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	fov;
	double	camera_x;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	bool	is_hit;
	int		side;
}	t_mlx;

char	world_map[mapheight][mapwidth];
void	set_player(t_mlx *mlx);
void	exit_error(char *str);

#endif