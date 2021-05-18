#include "cub.h"

int map_name(char *name, t_all *all)
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

int main(int argc, char **argv)
{
	t_all	all;

	init_all(&all);

	check_arguments(&all, argc, argv);
	load_images(&all);
	mlx_loop(all.mlx);
}