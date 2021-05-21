SRC = main.c \
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
		wallcasting.c\

OBJ = $(patsubst %c,%o,$(SRC))
NAME = cub3D

all: 		$(NAME)

$(NAME):	$(OBJ)
			gcc  -g  -Wall -Wextra -framework OpenGL -framework AppKit -L./libft -lft mlx/libmlx.a  $(OBJ) -o $(NAME)
fclean:
		rm -rf $(OBJ)
		rm -rf $(NAME)
re: fclean all
