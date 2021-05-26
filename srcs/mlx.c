#include "../cub.h"

void	my_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->img->addr + (y * all->img->ll + x * (all->img->bpp / 8));
	*(unsigned int *)dst = color;
}
