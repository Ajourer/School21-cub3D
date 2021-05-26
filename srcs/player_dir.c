#include "../cub.h"

void	set_n(t_all *all)
{
	all->info->dir_x = 0;
	all->info->dir_y = -1;
	all->info->plane_x = 0.66;
	all->info->plane_y = 0;
}

void	set_s(t_all *all)
{
	all->info->dir_x = 0;
	all->info->dir_y = 1;
	all->info->plane_x = -0.66;
	all->info->plane_y = 0;
}

void	set_w(t_all *all)
{
	all->info->dir_x = -1;
	all->info->dir_y = 0;
	all->info->plane_x = 0;
	all->info->plane_y = -0.66;
}

void	set_e(t_all *all)
{
	all->info->dir_x = 1;
	all->info->dir_y = 0;
	all->info->plane_x = 0;
	all->info->plane_y = 0.66;
}

void	player_dir(t_all *all, char letter)
{
	if (letter == 'N')
		set_n(all);
	if (letter == 'S')
		set_s(all);
	if (letter == 'W')
		set_w(all);
	if (letter == 'E')
		set_e(all);
}
