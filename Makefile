FILES = main.c \
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
		screen.c \
		wasd_keys.c \
		other_keys.c \

SRCS = $(addprefix srcs/, $(FILES))

CC = gcc

MLX_D = mlx/
LIB_D = libft/

MLX = libmlx.a
LIB = libft.a

CFLAGS = -g -Wall -Wextra -Werror -I$(MLX_D) -I. -I$(LIB_D)#-fsanitize=address

OBJS = $(SRCS:.c=.o)

NAME = cub3D

all: 		$(NAME)

$(NAME): $(MLX_D)$(MLX) $(OBJS) $(LIB_D)$(LIB)
		gcc   $(CFLAGS) -framework OpenGL -framework AppKit -L./libft -lft -L./mlx -lmlx $(OBJS) -o $(NAME)

$(MLX_D)$(MLX) : $(MLX_D)
	$(MAKE) -C $(MLX_D)

$(LIB_D)$(LIB) : $(LIB_D)
	@$(MAKE) -C $(LIB_D)

clean:
		$(MAKE) -C $(MLX_D) clean
		$(MAKE) -C $(LIB_D) clean
		$(RM) $(LIB_D)$(LIB)
		$(RM) $(OBJS)
		$(RM) $(MLX)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re