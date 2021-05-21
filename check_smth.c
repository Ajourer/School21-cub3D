#include "cub.h"

void check_arguments(t_all *all, int argc, char **argv)
{
	if (argc == 2 && map_name(argv[1], all) == 1)
	{
		parse_all(argv, all);
		all->win = mlx_new_window(all-, all->win->width, all->win->height,
							"cub3D");
	}
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", ft_strlen(argv[2]))
			 && !ft_strncmp(argv[2], "--save", 6))
	{
		parse_all(argv, all);
		all->screenshot = 1;
	}
	else
		error(6, all);
}

void check_color(t_all *all)
{
	if (!(all->clr->f_r >= 0 && all->clr->f_r <= 255))
		error(4, all);
	if (!(all->clr->f_g >= 0 && all->clr->f_g <= 255))
		error(4, all);
	if (!(all->clr->f_b >= 0 && all->clr->f_b <= 255))
		error(4, all);
	if (!(all->clr->c_r >= 0 && all->clr->c_r <= 255))
		error(4, all);
	if (!(all->clr->c_g >= 0 && all->clr->c_g <= 255))
		error(4, all);
	if (!(all->clr->c_b >= 0 && all->clr->c_b <= 255))
		error(4, all);
}
