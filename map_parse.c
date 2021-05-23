#include "cub.h"

void map_size(t_all *all, int i)
{
	int j;
	int max_size;

	all->map_h = num_of_lines(all->array) - i;
	max_size = 0;
	j = 0;
	while (all->array[i])
	{
		while (all->array[i][j])
			j++;
		if (max_size < j)
			max_size = j;
		j = 0;
		i++;
	}
	all->map_w = max_size;
//	int	q = 0;
//	while (all->array[q++])
//		printf("|||||||||%s\n", all->array[q]);
//	printf("%d\n", all->map_w);
//	printf("%d\n", all->map_h);
}

void create_map(t_all *all, int j)
{
	int i;
	int k;
	
	all->map = (char **)malloc((all->map_h + 1) * sizeof(char *));
	all->map[all->map_h] = 0;
	if (!all->map)
		error(1, all);
	k = all->map_h;
	i = 0;
	while (k)
	{
		all->map[i] = ft_strdup(all->array[j]);
		i++;
		j++;
		k--;
	}
}

void parse_map(t_all *all)
{
	int i;
	int j;

	i = 0;
	
	while (all->map[i])
	{
		j = 0;
		if (is_empty(all->map[i]))
			error(2, all);
		if (valid_string(all->map[i]))
			error(2, all);
		double_symb(all);
		while (all->map[i][j])
		{
			valid_check(i, j, all);
			j++;
		}
		i++;
	}
}

void valid_check(int i, int j, t_all *all)
{
	if (all->map[i][j] != '1' && all->map[i][j] != ' ')
	{
		
		if (i - 1 < 0 || j - 1 < 0 ||
			i + 1 >= all->map_h || j + 1 >= all->map_w || 
			all->map[i - 1][j] == ' ' || all->map[i + 1][j] == ' ' || 
			all->map[i][j - 1] == ' ' || all->map[i][j + 1] == ' ')
				error(2, all);
	}
}

void double_symb(t_all *all)
{
	int i;
	int j;
	int tmp;
	
	i = 0;
	tmp = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'N' || all->map[i][j] == 'S' ||
			all->map[i][j] == 'W' || all->map[i][j] == 'E')
				tmp++;
			j++;
		}
		i++;
	}
	if (tmp != 1)
		error(2, all);
}
