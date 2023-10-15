NAME	= cub3d

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

INC	= -I./test_raycast.h

OBJ_DIR	= obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM	= rm -rf

MLX_LIB = -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit ../minilibx_opengl_20191021/libmlx.a

SRCS	= 	main.c		\
			calc_dist_to_wall.c	\
			draw_wall_texture.c \
			exit_error.c	\
			ft_raycast.c	\
			set_player.c	\
			set_wall_texture.c
all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)	-o $(NAME) $(OBJS) $(MLX_LIB)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
