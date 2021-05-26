#include "../cub.h"

void	get_no(t_all *all, char *line, t_key *key)
{
	char	**split;
	int 	i;

	key->no = 0;
	key->counter++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(4, all);
	i = 0;
	all->tex->no = ft_strdup(split[1]);
	while (all->tex->no[i])
		i++;
	i -= 4;
	if (all->tex->no[i] != '.' && all->tex->no[i + 1] != 'x' &&
		all->tex->no[i + 2] != 'p' && all->tex->no[i + 3] != 'm')
		error(4, all);
	free_split(split);
}

void	get_so(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->so = 0;
	key->counter++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(4, all);
	i = 0;
	all->tex->so = ft_strdup(split[1]);
	while (all->tex->so[i])
		i++;
	i -= 4;
	if (all->tex->so[i] != '.' && all->tex->so[i + 1] != 'x' &&
		all->tex->so[i + 2] != 'p' && all->tex->so[i + 3] != 'm')
		error(4, all);
	free_split(split);
}

void	get_we(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->we = 0;
	key->counter++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(4, all);
	i = 0;
	all->tex->we = ft_strdup(split[1]);
	while (all->tex->we[i])
		i++;
	i -= 4;
	if (all->tex->we[i] != '.' && all->tex->we[i + 1] != 'x' &&
		all->tex->we[i + 2] != 'p' && all->tex->we[i + 3] != 'm')
		error(4, all);
	free_split(split);
}

void	get_ea(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->ea = 0;
	key->counter++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(4, all);
	i = 0;
	all->tex->ea = ft_strdup(split[1]);
	while (all->tex->ea[i])
		i++;
	i -= 4;
	if (all->tex->ea[i] != '.' && all->tex->ea[i + 1] != 'x' && 
	all->tex->ea[i + 2] != 'p' && all->tex->ea[i + 3] != 'm')
		error(4, all);
	free_split(split);
}

void 	get_s(t_all *all, char *line, t_key *key)
{
	char	**split;
	int		i;

	key->s = 0;
	key->counter++;
	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i != 2)
		error(4, all);
	i = 0;
	all->tex->sprites = ft_strdup(split[1]);
	while (all->tex->sprites[i])
		i++;
	i -= 4;
	if (all->tex->sprites[i] != '.' && all->tex->sprites[i + 1] != 'x' &&
		all->tex->sprites[i + 2] != 'p' && all->tex->sprites[i + 3] != 'm')
		error(4, all);
	free_split(split);
}