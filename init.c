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

static void	all_malloc(t_all *all)
{
	all->win = malloc(sizeof(t_window));
	all->tex = malloc(sizeof(t_tex));
	all->clr = malloc(sizeof(t_color));
	all->info = malloc(sizeof(t_info));
	all->n_i = malloc(sizeof(t_imgt));
	all->s_i = malloc(sizeof(t_imgt));
	all->w_i = malloc(sizeof(t_imgt));
	all->e_i = malloc(sizeof(t_imgt));
	all->sp_i = malloc(sizeof(t_imgt));
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
}

