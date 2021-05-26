#include "../cub.h"

int is_empty(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int valid_string(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != '2'
		&& line[i] != 'W' && line[i] != 'E' && line[i] != 'N' && line[i] != 'S')
			return (1);
		i++;
	}
	return (0);
}

int num_of_lines(char **file)
{
	int l;
	
	l = 0;
	while (file[l])
		l++;
	return (l);
}

//void fill_space(t_all *all, char *str)
//{
//	int i;
//
//	i = 0;
//	while (str[i])
//		i++;
//	if (i < all->map_w)
//	{
//		while (i <= all->map_w)
//			str[i] = ' ';
//	}
//}