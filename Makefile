NAME	= cub3d

CC	= gcc

#CFLAGS	= -Wall -Wextra -Werror

INC	= -I./include

OBJ_DIR	= obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM	= rm -rf

LIBFTDIR = libft

SRCS	= 	src/main.c		\
		src/error/error.c	\
		src/check/check_error.c	\
		src/check/check_file_name.c	\
		src/check/check_mapfile.c
all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS)	-L $(LIBFTDIR) -lft -o $(NAME) $(OBJS)

clean:
	@make fclean -C $(LIBFTDIR)
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
