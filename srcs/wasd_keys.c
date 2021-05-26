#include "cub.h"

void	w_button(t_all *all)
{
	if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x +
	(all->info->dir_x) * 0.08)] != '1')
		all->info->pos_x += all->info->dir_x * 0.08;
	if (all->map[(int)(all->info->pos_y + (all->info->dir_y) * 0.08)][(int)
	(all->info->pos_x)] != '1')
		all->info->pos_y += all->info->dir_y * 0.08;
}

void	s_button(t_all *all)
{
	if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x -
	(all->info->dir_x) * 0.08)] != '1')
		all->info->pos_x -= all->info->dir_x * 0.08;
	if (all->map[(int)(all->info->pos_y - (all->info->dir_y) * 0.08)][(int)
	(all->info->pos_x)] != '1')
		all->info->pos_y -= all->info->dir_y * 0.08;
}

void	a_button(t_all *all)
{
	if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x +
	(all->info->dir_y) * 0.08)] != '1')
		all->info->pos_x += all->info->dir_y * 0.08;
	if (all->map[(int)(all->info->pos_y - (all->info->dir_x) * 0.08)][(int)
	(all->info->pos_x)] != '1')
		all->info->pos_y -= all->info->dir_x * 0.08;
}

void	d_button(t_all *all)
{
	if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x -
	(all->info->dir_y) * 0.08)] != '1')
		all->info->pos_x -= all->info->dir_y * 0.08;
	if (all->map[(int)(all->info->pos_y + (all->info->dir_x) * 0.08)][(int)
	(all->info->pos_x)] != '1')
		all->info->pos_y += all->info->dir_x * 0.08;
}

int	which_key(int key, t_all *all)
{
	if (key == 13)
		w_button(all);
	if (key == 1)
		s_button(all);
	if (key == 0)
		a_button(all);
	if (key == 2)
		d_button(all);
	if (key == 124)
		turn_right(all);
	if (key == 123)
		turn_left(all);
	if (key == 53)
	{
		exit(0);
	}
	calculation(all);
	return (0);
}