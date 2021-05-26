#include "cub.h"

void		init_key(t_key *key)
{
	key->r = 1;
	key->no = 1;
	key->so = 1;
	key->we = 1;
	key->ea = 1;
	key->s = 1;
	key->f = 1;
	key->c = 1;
	key->counter = 0;
}
static	void	init_tex(t_tex *tex)
{
	tex->no = 0;
	tex->so = 0;
	tex->we = 0;
	tex->ea = 0;
	tex->sprites = 0;
}
static	void	init_img(t_img *img)
{
	img->img = 0;
	img->addr = 0;
	img->bpp = 0;
	img->ll = 0;
	img->endian = 0;
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

void		init_all(t_all *all)
{
	all_malloc(all);
	all->map_w = 0;
	all->map_h = 0;
	all->map = 0;
	all->spr = 0;
	//all->win = 0;
	//all->tex = 0;
	//all->clr = 0;
	all->array = 0;
	all->mlx = mlx_init();
	all->screenshot = 0;
	init_img(all->img);
	init_tex(all->tex);
	all->tex->so = 0;
	all->tex->we = 0;
	all->tex->no = 0;
	all->tex->ea = 0;
	all->tex->sprites = 0;
}

