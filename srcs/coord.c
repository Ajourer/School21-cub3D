#include "../cub.h"

void	num_of_sprites(t_all *all)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
				num++;
			j++;
		}
		i++;
	}
	all->num_spr = num;
}

void	sprites_coord(t_all *all)
{
	int	i;
	int	j;
	int	q;

	q = 0;
	i = 0;
	all->spr = malloc(sizeof(t_spr) * (all->num_spr));
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
			{
				all->spr[q].x = j + 0.5;
				all->spr[q].y = i + 0.5;
				q++;
			}
			j++;
		}
		i++;
	}
}

void	player_pos(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'N' || all->map[i][j] == 'S' ||
			all->map[i][j] == 'W' || all->map[i][j] == 'E')
			{
				all->info->pos_x = j + 0.5;
				all->info->pos_y = i + 0.5;
				player_dir(all, all->map[i][j]);
				all->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
