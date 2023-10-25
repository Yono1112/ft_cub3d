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

// error_message
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
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"
// # define FILENAME_ERROR "Missing required arguments"

#endif