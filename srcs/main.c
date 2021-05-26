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
	mlx_hook(all.win->win, 2, 0, &which_key, &all);
	mlx_hook(all.win->win, 17, 0, &close_button, &all);
	mlx_loop(all.mlx);
}
