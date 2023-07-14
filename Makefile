NAME	= cub3d

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

INC	= -I./include

OBJ_DIR	= obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM	= rm -rf

SRCS	= 	src/main.c	\
		src/check/check-mapfile.c





all:	$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
