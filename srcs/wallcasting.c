#include "cub.h"

void	calc_add_one(t_all *all, int x)
{
	all->info->cameraX = 2 * x / (double) all->win->width - 1;
	all->info->rayDirX
		= all->info->dir_x + all->info->plane_x * all->info->cameraX;
	all->info->rayDirY
		= all->info->dir_y + all->info->plane_y * all->info->cameraX;
	all->info->mapX = (int) all->info->pos_x;
	all->info->mapY = (int) all->info->pos_y;
	all->info->deltaDistX = fabs(1 / all->info->rayDirX);
	all->info->deltaDistY = fabs(1 / all->info->rayDirY);
	all->info->hit = 0;
}

void	calc_add_two(t_all *all)
{
	if (all->info->rayDirX < 0)
	{
		all->info->stepX = -1;
		all->info->sideDistX = (all->info->pos_x - all->info->mapX)
			* all->info->deltaDistX;
	}
	else
	{
		all->info->stepX = 1;
		all->info->sideDistX = (all->info->mapX + 1.0 - all->info->pos_x)
			* all->info->deltaDistX;
	}
	if (all->info->rayDirY < 0)
	{
		all->info->stepY = -1;
		all->info->sideDistY = (all->info->pos_y - all->info->mapY)
			* all->info->deltaDistY;
	}
	else
	{
		all->info->stepY = 1;
		all->info->sideDistY = (all->info->mapY + 1.0 - all->info->pos_y)
			* all->info->deltaDistY;
	}
}

void	calc_add_three(t_all *all)
{
	while (all->info->hit == 0)
	{
		if (all->info->sideDistX < all->info->sideDistY)
		{
			all->info->sideDistX += all->info->deltaDistX;
			all->info->mapX += all->info->stepX;
			all->info->side = 0;
		}
		else
		{
			all->info->sideDistY += all->info->deltaDistY;
			all->info->mapY += all->info->stepY;
			all->info->side = 1;
		}
		if (all->map[all->info->mapY][all->info->mapX] == '1')
			all->info->hit = 1;
	}
	if (all->info->side == 0)
		all->info->perpWallDist = (all->info->mapX - all->info->pos_x
				+ (1 - all->info->stepX) / 2) / all->info->rayDirX;
	else
		all->info->perpWallDist = (all->info->mapY - all->info->pos_y
				+ (1 - all->info->stepY) / 2) / all->info->rayDirY;
	all->info->lineHeight = (int)(all->win->height
			/ all->info->perpWallDist);
}

void	calc_add_four(t_all *all, int x)
{
	int		y;
	int		color;
	t_imgt	texture;

	all->info->drawStart = -all->info->lineHeight
		/ 2 + all->win->height / 2;
	if (all->info->drawStart < 0)
		all->info->drawStart = 0;
	all->info->drawEnd = all->info->lineHeight / 2 + all->win->height / 2;
	if (all->info->drawEnd >= all->win->height)
		all->info->drawEnd = all->win->height - 1;
	texture = what_color(all);
	y = all->info->drawStart;
	while (y < all->info->drawEnd)
	{
		all->info->texY
			= (int) all->info->texPos & (all->info->texHeight - 1);
		all->info->texPos += all->info->step;
		color = ((int *)texture.addr)[all->info->texHeight
			* all->info->texY + all->info->texX];
		my_pixel_put(all, x, y, color);
		y++;
	}
}

int	calculation(t_all *all)
{
	int	x;

	x = 0;
	all->info->zBuffer = malloc(all->win->width * sizeof(double));
	floor_paint(all);
	ceiling_paint(all);
	while (x < all->win->width)
	{
		calc_add_one(all, x);
		calc_add_two(all);
		calc_add_three(all);
		calc_add_four(all, x);
		all->info->zBuffer[x] = all->info->perpWallDist;
		x++;
	}
	sprites(all, all->s);
	free(all->info->zBuffer);
	free(all->s->sprite_order);
	free(all->s->sprite_distance);
	if (all->screenshot != 1)
		mlx_put_image_to_window(all->mlx, all->win->win, all->img->img, 0, 0);
	return (0);
}
