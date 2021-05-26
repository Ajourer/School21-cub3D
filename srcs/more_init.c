#include "../cub.h"

void	init_key(t_key *key)
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

void	init_tex(t_all *all)
{
	all->tex->no = 0;
	all->tex->so = 0;
	all->tex->we = 0;
	all->tex->ea = 0;
	all->tex->sprites = 0;
}

void	init_textures(t_imgt *t)
{
	t->img = 0;
	t->addr = 0;
	t->bpp = 0;
	t->ll = 0;
	t->endian = 0;
	t->w = 0;
	t->h = 0;
	t->bpp = 0;
}
