#include "../cub.h"

int	map_name(char *name, t_all *all)
{
	while (name && *name && *name != '.')
		name++;
	if (*name == '.')
		name++;
	if (ft_strcmp(name, "cub") == 0)
		return (1);
	else
		error(3, all);
	return (0);
}

int	close_button(t_all *all)
{
	free_all(all);
	exit(0);
	return (0);
}

int	move_w(int key, t_all *all)
{
	if (key == 53)
	{
		exit(0);
	}
	if (key == 13)
	{
		if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x +
				(all->info->dir_x) * 0.08)] != '1')
			all->info->pos_x += all->info->dir_x * 0.08;
		if (all->map[(int)(all->info->pos_y + (all->info->dir_y) * 0.08)][(int)
		(all->info->pos_x)] != '1')
			all->info->pos_y += all->info->dir_y * 0.08;
	}
	if (key == 1)
	{
		if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x -
		(all->info->dir_x) * 0.08)] != '1')
			all->info->pos_x -= all->info->dir_x * 0.08;
		if (all->map[(int)(all->info->pos_y - (all->info->dir_y) * 0.08)][(int)
				(all->info->pos_x)] != '1')
			all->info->pos_y -= all->info->dir_y * 0.08;
	}
	if (key == 0)
	{
		if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x +
		(all->info->dir_y) * 0.08)] != '1')
			all->info->pos_x += all->info->dir_y * 0.08;
		if (all->map[(int)(all->info->pos_y - (all->info->dir_x) * 0.08)][(int)
		(all->info->pos_x)] != '1')
			all->info->pos_y -= all->info->dir_x * 0.08;
	}
	if (key == 2)
	{
		if (all->map[(int)(all->info->pos_y)][(int)(all->info->pos_x -
		(all->info->dir_y) * 0.08)] != '1')
			all->info->pos_x -= all->info->dir_y * 0.08;
		if (all->map[(int)(all->info->pos_y + (all->info->dir_x) * 0.08)][(int)
		(all->info->pos_x)] != '1')
			all->info->pos_y += all->info->dir_x * 0.08;
	}
	if (key == 124)
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
	if (key == 123)
	{
		float	old_dir_x;
		float	old_plane_x;

		old_dir_x = all->info->dir_x;
		all->info->dir_x = all->info->dir_x * cos(-0.07)
			- all->info->dir_y * sin(-0.07);
		all->info->dir_y = old_dir_x * sin(-0.07)
			+ all->info->dir_y * cos(-0.07);
		old_plane_x = all->info->plane_x;
		all->info->plane_x = all->info->plane_x * cos(-0.07)
			- all->info->plane_y * sin(-0.07);
		all->info->plane_y = old_plane_x * sin(-0.07)
			+ all->info->plane_y * cos(-0.07);
	}
	calculation(all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_all(&all);
	check_arguments(&all, argc, argv);
	load_images(&all);
	all.img->img = mlx_new_image(all.mlx, all.win->width, all.win->height);
	all.img->addr = mlx_get_data_addr(all.img->img, &all.img->bpp,
			 &all.img->ll, &all.img->endian);
	calculation(&all);
	if (all.screenshot == 1)
		screen(&all);
	mlx_hook(all.win->win, 2, 0, &move_w, &all);
	mlx_hook(all.win->win, 17, 0, &close_button, &all);
	mlx_loop(all.mlx);
}
