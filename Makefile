NAME	= cub3D

CC	= gcc

#CFLAGS	= -Wall -Wextra -Werror

DEBUG_FLAGS = -g -O0

INC	= -I./include

OBJ_DIR	= obj

DEBUG_OBJ_DIR = debug_obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

DEBUG_OBJS = $(SRCS:%.c=$(DEBUG_OBJ_DIR)/%.o)

RM	= rm -rf

LIBFTDIR = libft

MLX_LIB = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit ./minilibx_opengl_20191021/libmlx.a

MLX_DIR = minilibx_opengl_20191021

SRCS	= 	src/main.c		\
		src/exit/exit_error.c	\
		src/check/check_error.c	\
		src/check/check_file_name.c	\
		src/check/check_mapfile.c \
		src/mlx/run_mlx.c \
		src/mlx/init/ft_init_mlx.c \
		src/mlx/init/set_player.c \
		src/mlx/init/set_wall_texture.c \
		src/mlx/raycast/ft_raycast.c \
		src/mlx/raycast/calc_wall_height.c \
		src/mlx/draw/draw_wall_texture_ceiling_floor.c \
		src/mlx/raycast/calc_dist_to_wall.c \
		src/exit/ft_destroy.c \
		src/mlx/press_key/ft_press_key.c \
		src/exit/free.c \
		src/mlx/press_key/move_back.c \
		src/mlx/press_key/move_forward.c \
		src/mlx/press_key/move_left.c \
		src/mlx/press_key/move_right.c \
		src/mlx/press_key/rotate_left.c \
		src/mlx/press_key/rotate_right.c \

all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DEBUG_OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@make -C ${MLX_DIR}
	$(CC) $(CFLAGS)	-L $(LIBFTDIR) -lft -o $(NAME) $(OBJS) $(MLX_LIB)

clean:
	@make fclean -C $(LIBFTDIR)
	@make clean -C $(MLX_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

lldb: $(DEBUG_OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -L $(LIBFTDIR) -lft -o $(NAME) $(DEBUG_OBJS)
	@lldb ./$(NAME)

.PHONY: all clean fclean re lldb
