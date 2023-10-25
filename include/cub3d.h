#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "defines.h"

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
	char	**map;
	char	*ceiling_num_char[3];
	char	*floor_num_char[3];
}	t_map;

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
	t_map	*mapdata;
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

enum Error
{
	Argument_Error,
	Openfile_Error,
	Filename_Error,
	Readfile_Error,
	Mapargument_Error,
	Texture_Error,
	Invalid_Argument_In_Map_Error,
	Num_Arguments_Error,
	Hole_In_Map,
	Open_Texture_Error,
	Comma_Error,
	Texture_is_big
};

//check-mapfile
void	error(int error_num);
void	check_error(const int argc, const char **argv,t_map *mapdata);
void	check_mapfile(char **argv, t_map *mapdata);
void	file_name(const int argc, const char **argv);
// raycast
void	run_mlx(t_map *mapdate);
void	ft_init_mlx(t_mlx *mlx, t_map *mapdate);
void	set_player(t_mlx *mlx, char **map);
void	exit_error(char *str);
int		ft_raycast(t_mlx *mlx);
void	draw_wall_texture_ceiling_floor(t_mlx *mlx, size_t x);
void	set_wall_texture(t_mlx *mlx, t_map *mapdata);
int		ft_destroy(char *str, t_mlx *mlx);
int		ft_press_key(int i, t_mlx *mlx);
void	init_raycast_value(t_mlx *mlx, size_t x);
void	print_map(char **map);
double	calc_dist_to_wall(t_mlx *mlx, double ray_direct);
int		ft_destroy(char *str, t_mlx *mlx);
int		ft_press_key(int key_num, t_mlx *mlx);

#endif
