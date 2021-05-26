#include "../cub.h"

static	void	init_win(t_window *win)
{
	win->width = 0;
	win->height = 0;
	win->win = 0;
}

static	void	init_img(t_img *img)
{
	img->img = 0;
	img->addr = 0;
	img->bpp = 0;
	img->ll = 0;
	img->endian = 0;
}

static	void	init_sprite(t_sprites *s)
{
	s->sprite_order = 0;
	s->sprite_distance = 0;
	s->sprite_x = 0;
	s->sprite_y = 0;
	s->inv_det = 0;
	s->transform_x = 0;
	s->transform_y = 0;
	s->sprite_screen_x = 0;
	s->sprite_height = 0;
	s->draw_start_y = 0;
	s->draw_end_y = 0;
	s->sprite_width = 0;
	s->draw_start_x = 0;
	s->draw_end_x = 0;
	s->stripe = 0;
	s->tex_x = 0;
	s->tex_y = 0;
	s->color = 0;
}

static void	all_malloc(t_all *all)
{
	all->win = malloc(sizeof(t_window) * 1);
	all->tex = malloc(sizeof(t_tex) * 1);
	all->clr = malloc(sizeof(t_color) * 1);
	all->info = malloc(sizeof(t_info) * 1);
	all->n_i = malloc(sizeof(t_imgt) * 1);
	all->s_i = malloc(sizeof(t_imgt) * 1);
	all->w_i = malloc(sizeof(t_imgt) * 1);
	all->e_i = malloc(sizeof(t_imgt) * 1);
	all->sp_i = malloc(sizeof(t_imgt) * 1);
	all->img = malloc(sizeof(t_img) * 1);
	all->s = malloc(sizeof(t_sprites) * 1);
}

void	init_all(t_all *all)
{
	all_malloc(all);
	all->map_w = 0;
	all->map_h = 0;
	all->map = 0;
	all->mlx = mlx_init();
	all->screenshot = 0;
	init_win(all->win);
	init_tex(all);
	init_img(all->img);
	init_sprite(all->s);
	init_textures(all->n_i);
	init_textures(all->s_i);
	init_textures(all->w_i);
	init_textures(all->e_i);
	init_textures(all->sp_i);
}
