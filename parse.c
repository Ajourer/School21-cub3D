#include "cub.h"

int		parse_file(char *file, t_all *all)
{
	int fd;
	char *line; //куда записывается строка, считываемая gnl
	char *newline; //строка файла, склеенная вместе с \n

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error(5, all);
	newline = (char*)malloc(1);
	if (!newline)
		error(1, all);
	newline[0] = '\0';
	while (get_next_line(fd, &line) > 0)
	{
		newline = ft_strjoin(newline, line);
		newline = ft_strjoin(newline, "\n");
		free(line);
	}
	newline = ft_strjoin(newline, line);
	free(line);
	all->array = ft_split(newline, '\n');
	free(newline);
	close(fd);
	return (0);
}

void	nswe(t_all *all, char *s, t_key *key)
{
	if (key->no && s[0] == 'N' && s[1] == 'O' && s[2] == ' ')
		get_no(all, s, key);
	else if (key->so && s[0] == 'S' && s[1] == 'O' && s[2] == ' ')
		get_so(all, s, key);
	else if (key->we && s[0] == 'W' && s[1] == 'E' && s[2] == ' ')
		get_we(all, s, key);
	else if (key->ea && s[0] == 'E' && s[1] == 'A' && s[2] == ' ')
		get_ea(all, s, key);
}

int		type_identifier(t_all *all, char *str, t_key *key)
{
	nswe(all, str, key);
	if (key->r && str[0] == 'R' && str[1] == ' ')
		get_r(all, str, key);
	else if (key->s && str[0] == 'S' && str[1] == ' ')
		get_s(all, str, key);
	else if (key->f && str[0] == 'F' && str[1] == ' ')
		get_f(all, str, key);
	else if (key->c && str[0] == 'C' && str[1] == ' ')
		get_c(all, str, key);
	return (1);
}


void map_part(int i, t_all *all)
{
	while (is_empty(all->array[i]))
		i++;
	map_size(all, i);

	create_map(all, i);
	parse_map(all);
	num_of_sprites(all);
	sprites_coord(all);
	player_pos(all);
}

void	  parse_all(char **argv, t_all *all)
{
	int i;
	t_key key;

	i = 0;
	init_key(&key);
	parse_file(argv[1], all);
	while (all->array[i])
	{
		if (is_empty(all->array[i]))
		{
			i++;
			continue;
		}
		type_identifier(all, all->array[i], &key);
		if (key.counter == 8)
		{
			i++;
			break;
		}
		i++;
	}
	if (key.counter != 8)
		error(4, all);
	check_color(all);
	map_part(i, all);
}
