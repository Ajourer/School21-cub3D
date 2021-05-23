SRCS = main.c \
	  parse.c \
	  map_parse.c \
	  get_next_line.c \
	  get_next_line_utils.c \
		error.c \
		addons.c \
		get_sequel.c \
		init.c \
		free.c \
		get.c \
		get_triquel.c \
		coord.c \
		player_dir.c \
		check_tex.c \
		check_smth.c \
		mlx.c \
		wallcasting.c \
		sprites.c \

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address


OBJS = $(SRCS:.c=.o)
NAME = cub3D

all: 		$(NAME)

$(NAME):	$(OBJS)
			gcc   $(CFLAGS) -framework OpenGL -framework AppKit -L./libft -lft mlx/libmlx.a  $(OBJS) -o $(NAME)
clean:
		rm -rf $(OBJS)
fclean:
		rm -rf $(OBJS)
		rm -rf $(NAME)
re: fclean all
