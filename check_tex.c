#include "cub.h"

void	load_texture(t_all *all, char *dir, t_imgt *dir_st)
{
	dir_st->img = mlx_xpm_file_to_image(all->mlx, dir, &dir_st->w,
									  &dir_st->h);
	if (dir_st->img == NULL)
		error(7, all);
	dir_st->addr = mlx_get_data_addr(dir_st->img, &dir_st->bpp, &dir_st->ll,
					  &dir_st->endian);
}

void 	load_images(t_all *all)
{
	load_texture(all, all->tex->no, all->n_i);
	load_texture(all, all->tex->so, all->s_i);
	load_texture(all, all->tex->we, all->w_i);
	load_texture(all, all->tex->ea, all->e_i);
	load_texture(all, all->tex->sprites, all->sp_i);
}