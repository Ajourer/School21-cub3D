#include "cub.h"

void	free_all(t_all *all)
{
	int i;

	i = 0;
	//free_first(all);
	if (all->map != 0)
	{
		while (all->map[i])
		{
			free(all->map[i]);
			i++;
		}
		free(all->map);
	}
}

