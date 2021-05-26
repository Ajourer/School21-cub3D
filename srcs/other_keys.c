#include "cub.h"

void	turn_right(t_all *all)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = all->info->dir_x;
	all->info->dir_x = all->info->dir_x * cos(0.07)
		- all->info->dir_y * sin(0.07);
	all->info->dir_y = old_dir_x * sin(0.07) + all->info->dir_y * cos(0.07);
	old_plane_x = all->info->plane_x;
	all->info->plane_x = all->info->plane_x * cos(0.07)
		- all->info->plane_y * sin(0.07);
	all->info->plane_y = old_plane_x * sin(0.07)
		+ all->info->plane_y * cos(0.07);
}

void	turn_left(t_all *all)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = all->info->dir_x;
	all->info->dir_x = all->info->dir_x * cos(-0.07)
		- all->info->dir_y * sin(-0.07);
	all->info->dir_y = old_dir_x * sin(-0.07) + all->info->dir_y * cos(-0.07);
	old_plane_x = all->info->plane_x;
	all->info->plane_x = all->info->plane_x * cos(-0.07)
		- all->info->plane_y * sin(-0.07);
	all->info->plane_y = old_plane_x * sin(-0.07)
		+ all->info->plane_y * cos(-0.07);
}

int	close_button(t_all *all)
{
	free_all(all);
	exit(0);
	return (0);
}
