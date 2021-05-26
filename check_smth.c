#include "cub.h"

void check_empty(char *file, t_all *all)
{
	int		fd;
	char	*line;
	int		flag;
	flag = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(5, all);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, all->map[0]) == 0)
			flag = 1;
		if (flag == 1 && *line == 0)
			error(2, all);
		free(line);
	}
	free(line);
	close(fd);
}

void check_arguments(t_all *all, int argc, char **argv)
{
	if (argc == 2 && map_name(argv[1], all) == 1)
	{
		parse_all(argv, all);
		check_empty(argv[1], all);
		all->win->win = mlx_new_window(all->mlx, all->win->width,
								 all->win->height,"cub3D");
	}
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", ft_strlen(argv[2]))
			 && !ft_strncmp(argv[2], "--save", 6))
	{
		parse_all(argv, all);
		check_empty(argv[1], all);
		all->screenshot = 1;
	}
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
