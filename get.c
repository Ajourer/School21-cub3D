#include "cub.h"

void	valid_r_char(char *string, t_all *all)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] == 'R' || string[i] == ' ' ||
			(string[i] <= '9' && string[i] >= '0'))
			i++;
		else
			error(4, all);
	}
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

void	check_r(char **split, t_all *all)
{
	int i;
	int zero;

	zero = 0;
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error(4, all);
	i = -1;
	while (split[1][++i] == '0')
		zero++;
	if (zero != 0)
		error(4, all);
	i = -1;
	while (split[2][++i] == '0')
		zero++;
	if (zero != 0)
		error(4, all);
}

void get_r(t_all *all, char *string, t_key *key)
{
	char **split;
	
	key->r = 0;
	key->counter++;
	valid_r_char(string, all);
	split = ft_split(string, ' ');
	check_r(split, all);
	if (ft_atoi(split[1]) < 0 || ft_atoi(split[1]) > 2560)
		all->win->width = 2560;
	else
		all->win->width = ft_atoi(split[1]);
	if (ft_atoi(split[2]) < 0 || ft_atoi(split[2]) > 1440)
		all->win->height = 1440;
	else
		all->win->height = ft_atoi(split[2]);
	if (all->win->width < 100 || all->win->height < 100)
	{
		all->win->width = 100;
		all->win->height = 100;
	}
	free_split(split);
}