#include "../cub.h"

void	comma_count(char *str, t_all *all)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		error(4, all);
}

void	get_f(t_all *all, char *line, t_key *key)
{
	char	**split_two;
	char	**split_three;
	int		i;

	i = 0;
	key->f = 0;
	key->counter++;
	valid_f_char(line, all);
	split_two = ft_split(line, ' ');
	while (split_two[i])
		i++;
	if (i != 2)
		error(4, all);
	comma_count(split_two[1], all);
	split_three = ft_split(split_two[1], ',');
	i = 0;
	while (split_three[i])
		i++;
	if (i != 3)
		error(4, all);
	all->clr->f_r = ft_atoi(split_three[0]);
	all->clr->f_g = ft_atoi(split_three[1]);
	all->clr->f_b = ft_atoi(split_three[2]);
	free_split(split_two);
	free_split(split_three);
}

void	valid_f_char(char *line, t_all *all)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 'F'
			|| line[i] == ',' || (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(4, all);
	}
}

void	get_c(t_all *all, char *line, t_key *key)
{
	char	**split_two;
	char	**split_three;
	int		i;

	i = 0;
	key->c = 0;
	key->counter++;
	valid_c_char(line, all);
	split_two = ft_split(line, ' ');
	while (split_two[i])
		i++;
	if (i != 2)
		error(4, all);
	comma_count(split_two[1], all);
	split_three = ft_split(split_two[1], ',');
	i = 0;
	while (split_three[i])
		i++;
	if (i != 3)
		error(4, all);
	all->clr->c_r = ft_atoi(split_three[0]);
	all->clr->c_g = ft_atoi(split_three[1]);
	all->clr->c_b = ft_atoi(split_three[2]);
	free_split(split_two);
	free_split(split_three);
}

void	valid_c_char(char *line, t_all *all)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == 'C'
			|| line[i] == ',' || (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			error(4, all);
	}
}
