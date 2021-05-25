#ifndef CUB_H
# define CUB_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"

typedef	struct	s_imgt //структура для текстур в зависимости от стороны света
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int 		endian;
	int			w;
	int			h;
}				t_imgt;

typedef struct	s_img
{
	void *img;
	char *addr;
	int bpp;
	int ll;
	int endian;
}				t_img;

typedef struct	s_sprites
{
	int			*sprite_order;
	double		*sprite_distance;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			tex_x;
	int			tex_y;
	int			color;
}				t_sprites;

typedef struct	s_spr
{
	double 			x;
	double 			y;
}				t_spr;

typedef struct	s_color
{
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
}				t_color;

typedef struct	s_window
{
	int			width;
	int			height;
	void 		*win;
}				t_window;

typedef struct	s_tex //сюда закидываем путь к текстурам
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sprites;
}				t_tex;

typedef struct	s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_esc;
	//int			**texture;
	double		moveSpeed;
	double		rotSpeed;
	
	double		*zBuffer;
	
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int 		mapX;
	int 		mapY;
	double 		sideDistX;
	double 		sideDistY;
	double 		deltaDistX;
	double 		deltaDistY;
	double 		perpWallDist;
	int 		stepX;
	int 		stepY;
	int 		hit;
	int 		side;
	int 		lineHeight;
	int 		drawStart;
	int 		drawEnd;
	int 		texNum;
	double 		wallX;
	int 		texX;
	int			texY;
	double		step;
	double		texPos;
	int 		texWidth;
	int 		texHeight;
}				t_info;



typedef struct	s_key
{
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
	int			counter;
}				t_key;

typedef struct	s_all
{
	void		*mlx;
	void		*window;
	int			map_w;
	int			map_h;
	char 		**map; //наша заполненная карта с выделенной под нее памятью
	t_window	*win;
	t_tex		*tex;
	t_color		*clr;
	t_spr		*spr;
	t_info		*info;
	t_imgt		*n_i;
	t_imgt		*s_i;
	t_imgt		*w_i;
	t_imgt		*e_i;
	t_imgt		*sp_i;
	t_img 		*img;
	
	//int			color;
	int			num_spr;
	char		**array; //массив из строк файла
	int			screenshot;
	t_sprites 	*s;
}				t_all;

//typedef struct	s_rayCast
//{
//	double		cameraX;
//	double		rayDirX;
//	double		rayDirY;
//	int 		mapX;
//	int 		mapY;
//	double 		sideDistX;
//	double 		sideDistY;
//	double 		deltaDistX;
//	double 		deltaDistY;
//	double 		perpWallDist;
//	int 		stepX;
//	int 		stepY;
//	int 		hit;
//	int 		side;
//	int 		lineHeight;
//	int 		drawStart;
//	int 		drawEnd;
//	int 		texNum;
//	double 		wallX;
//	int 		texX;
//	int			texY;
//	double		step;
//	double		texPos;
//
//}				t_rayCast;

int		get_next_line(int fd, char **line);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(char *s, int c);
size_t	len_before_n(const char *s);
int		n_found(char **cash, char **line);
int		n_not_found(char **cash, char **line);
void	map_size(t_all *all, int i);
void	create_map(t_all *all, int j);
void	free_all(t_all *all);
void	error(int error, t_all *all);
int		is_empty(char *line);
int		valid_string(char *str);
void	parse_map(t_all *all);
int		parse_file(char *file, t_all *all);
void	valid_check(int i, int j, t_all *all);
void	init_key(t_key *key);
int 	type_identifier(t_all *all, char *str, t_key *key);
void	valid_r_char(char *string, t_all *all);
void	check_r(char **split, t_all *all);
void	get_r(t_all *all, char *string, t_key *key);
void	free_split(char **split);
void	get_no(t_all *all, char *line, t_key *key);
void	get_so(t_all *all, char *line, t_key *key);
void	get_we(t_all *all, char *line, t_key *key);
void	get_ea(t_all *all, char *line, t_key *key);
void 	get_s(t_all *all, char *line, t_key *key);
void	nswe(t_all *all, char *s, t_key *keys);
void 	another(t_all *all, char *s, t_key *keys);
void	parse_all(char **argv, t_all *all);
int		map_name(char *name, t_all *all);
void	map_part(int i, t_all *all);
int		num_of_lines(char **file);
void	double_symb(t_all *all);
void	get_f(t_all *all, char *line, t_key *key);
void	valid_f_char(char *line, t_all *all);
void	get_c(t_all *all, char *line, t_key *key);
void	valid_c_char(char *line, t_all *all);
void	comma_count(char *str, t_all *all);
void	init_all(t_all *all);
void	num_of_sprites(t_all *all);
void	sprites_coord(t_all *all);
void	set_n(t_all *all);
void	set_s(t_all *all);
void	set_w(t_all *all);
void	set_e(t_all *all);
void	player_dir(t_all *all, char letter);
void	player_pos(t_all *all);
void	check_color(t_all *all);
void	load_texture(t_all *all, char *dir, t_imgt *dir_st);
void 	load_images(t_all *all);
void	check_arguments(t_all *all, int argc, char **argv);
void	my_pixel_put(t_all *all, int x, int y, int color);
int 	calculation(t_all *all);
void	sprites(t_all *all, t_sprites *s);
void	screen(t_all *all);
void	fill_space(t_all *all, char *str);

#endif
