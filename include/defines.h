#ifndef DEFINES_H
# define DEFINES_H

# define MAP_WIDTH 16
# define MAP_HEIGHT 16
# define WINSIZE_WIDTH 400
# define WINSIZE_HEIGTH 400
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
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17 
# define GAME_NAME "cub3D"
// # define ESC_DESTROY "press ESC key"
// # define CLOSE_BUTTON_DESTROY "press close button"
# define DESTROY_PREFIX "\x1b[96mFINISH\x1b[0m"

// error_message
# define ERROR_PREFIX "\e[31mERROR\e[m: "
# define ARGUMENT_ERROR "Missing required arguments"
# define FILENAME_ERROR "Missing filename"
# define OPENFILE_ERROR "Cannot open the file"
# define READFILE_ERROR "Cannnot read the file"
# define TEXTURE_ERROR "Texture error"
# define NOT_ENOUGH_ARGUMENT_ERROR "Has not enough arguments"
# define MAP_ARGUMENT_ERROR "Invalid arguments in map"
# define NUM_ARGUMENT_ERROR "Invalid number of nums"
# define HOLE_MAP_ERROR "There is hoge in map"
# define OPEN_TEXTURE_ERROR "Cannot open the texture"
# define COMMA_ERROR "Commma error"
# define TEXTURE_BIG_ERROR "Texture number error"
# define MLX_INIT_ERROR "Cannot run mlx_init()"
# define MLX_WINDOW_ERROR "Cannot run mlx_new_window()"
# define SET_PLAYER_ERROR "Start position is not set"
# define IMG_PTR_ERROR "Cannot convert xpm to image in mlx_xpm_file_to_image()"
# define DETA_ADDR_ERROR\
		"Cannot get memory address of image in mlx_get_data_addr()"
# define INDEX_TEXTURE_ERROR "cannot set index_texture in draw_wall_texture()"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"

#endif