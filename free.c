#include "cub.h"

void	free_first(t_all *all)
{
//	free(all->tex->so);
//	free(all->tex->we);
//	free(all->tex->no);
//	free(all->tex->ea);
//	free(all->tex->sprites);
	free(all->tex);
	free(all->clr);
	free(all->img);
	free(all->info);
	free(all->n_i);
	free(all->s_i);
	free(all->w_i);
	free(all->e_i);
	free(all->sp_i);
	free(all->mlx);
	free(all->win);
	free(all->s);
}

void	free_all(t_all *all)
{
	int i;

	i = 0;
	free_first(all);
	if (all->map != 0)
	{
		while (all->map[i])
		{
			free(all->map[i]);
			i++;
		}
		free(all->map);
	}
}

