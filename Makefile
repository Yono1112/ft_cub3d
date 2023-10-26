NAME	= cub3d

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

DEBUG_FLAGS = -g -O0

INC	= -I./include

OBJ_DIR	= obj

DEBUG_OBJ_DIR = debug_obj

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

DEBUG_OBJS = $(SRCS:%.c=$(DEBUG_OBJ_DIR)/%.o)

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

$(DEBUG_OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INC) -c $< -o $@

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

lldb: $(DEBUG_OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -L $(LIBFTDIR) -lft -o $(NAME) $(DEBUG_OBJS)
	@lldb ./$(NAME)

.PHONY: all clean fclean re lldb
