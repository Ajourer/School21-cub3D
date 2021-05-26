#include "cub.h"

int	r_g_b(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	floor_paint(t_all *all)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = all->win->width / 2;
	color = r_g_b(all->clr->f_r, all->clr->f_g, all->clr->f_b);
	while (x < all->win->width)
	{
		while (y < all->win->height)
		{
			my_pixel_put(all, x, y, color);
			y++;
		}
		y = all->win->height / 2;
		x++;
	}
}

void	ceiling_paint(t_all *all)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	color = r_g_b(all->clr->c_r, all->clr->c_g, all->clr->c_b);
	while (x < all->win->width)
	{
		while (y < all->win->height / 2)
		{
			my_pixel_put(all, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

void	what_color_sequel(t_all *all)
{
	all->info->wallX -= floor((all->info->wallX));
	all->info->texWidth = 64;
	all->info->texHeight = 64;
	all->info->texX = (int)(all->info->wallX
			* (double)all->info->texWidth);
	if (all->info->side == 0 && all->info->rayDirX > 0)
		all->info->texX = all->info->texWidth - all->info->texX - 1;
	if (all->info->side == 1 && all->info->rayDirY < 0)
		all->info->texX = all->info->texWidth - all->info->texX - 1;
	all->info->step = 1.0 * all->info->texHeight / all->info->lineHeight;
	all->info->texPos = (all->info->drawStart - all->win->height / 2
			+ all->info->lineHeight / 2) * all->info->step;
}

t_imgt	what_color(t_all *all)
{
	t_imgt	color;

	if (all->info->side == 0 && all->info->stepX > 0)
		color = *all->e_i;
	if (all->info->side == 0 && all->info->stepX < 0)
		color = *all->w_i;
	if (all->info->side == 1 && all->info->stepY < 0)
		color = *all->n_i;
	if (all->info->side == 1 && all->info->stepY > 0)
		color = *all->s_i;
	if (all->info->side == 0)
		all->info->wallX = all->info->pos_y
			+ all->info->perpWallDist * all->info->rayDirY;
	else
		all->info->wallX = all->info->pos_x
			+ all->info->perpWallDist * all->info->rayDirX;
	what_color_sequel(all);
	return (color);
}
