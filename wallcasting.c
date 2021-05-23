#include "cub.h"

int r_g_b(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	floor_paint(t_all *all)
{
	int x;
	int y;
	int color;
	

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
	int x;
	int y;
	int color;

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

t_imgt what_color(t_all *all)
{
	t_imgt color;

	if (all->info->side == 0 && all->info->stepX > 0)
		color = *all->e_i;
	if (all->info->side == 0 && all->info->stepX < 0)
		color = *all->w_i;
	if (all->info->side == 1 && all->info->stepY < 0)
		color = *all->n_i;
	if (all->info->side == 1 && all->info->stepY > 0)
		color = *all->s_i;
	
	if (all->info->side == 0)
		all->info->wallX = all->info->pos_y +
						   all->info->perpWallDist * all->info->rayDirY;
	else
		all->info->wallX = all->info->pos_x +
						   all->info->perpWallDist * all->info->rayDirX;
	all->info->wallX -= floor((all->info->wallX));

	all->info->texWidth = 64;
	all->info->texHeight = 64;
	all->info->texX = (int) (all->info->wallX *
							 (double) all->info->texWidth);
	if (all->info->side == 0 && all->info->rayDirX > 0)
		all->info->texX = all->info->texWidth - all->info->texX - 1;
	if (all->info->side == 1 && all->info->rayDirY < 0)
		all->info->texX = all->info->texWidth - all->info->texX - 1;

	all->info->step = 1.0 * all->info->texHeight / all->info->lineHeight;

	all->info->texPos = (all->info->drawStart - all->win->height / 2 +
			all->info->lineHeight / 2) * all->info->step;
	return (color);
}

int calculation(t_all *all)
{
	int x;
	
	x = 0;
	all->info->zBuffer = malloc(all->win->width * sizeof(double));

	//printf("|%f|\n", all->info->pos_x);
	floor_paint(all);
	ceiling_paint(all);
	while (x < all->win->width)
	{
		all->info->cameraX = 2 * x / (double) all->win->width - 1;
		all->info->rayDirX =
				all->info->dir_x + all->info->plane_x * all->info->cameraX;
		all->info->rayDirY =
				all->info->dir_y + all->info->plane_y * all->info->cameraX;
		all->info->mapX = (int) all->info->pos_x;
		all->info->mapY = (int) all->info->pos_y;
		all->info->deltaDistX = fabs(1 / all->info->rayDirX);
		all->info->deltaDistY = fabs(1 / all->info->rayDirY);
		all->info->hit = 0;

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
			all->info->perpWallDist = (all->info->mapX - all->info->pos_x +
					(1 - all->info->stepX) / 2) / all->info->rayDirX;
		else
			all->info->perpWallDist = (all->info->mapY - all->info->pos_y +
					(1 - all->info->stepY) / 2) / all->info->rayDirY;

		all->info->lineHeight = (int) (all->win->height /
									   all->info->perpWallDist);

		all->info->drawStart =
				-all->info->lineHeight / 2 + all->win->height / 2;
		if (all->info->drawStart < 0)
			all->info->drawStart = 0;
		all->info->drawEnd = all->info->lineHeight / 2 + all->win->height / 2;
		if (all->info->drawEnd >= all->win->height)
			all->info->drawEnd = all->win->height - 1;
		t_imgt texture;
		
		texture = what_color(all);
		int y;
		int color;

		y = all->info->drawStart;
		while (y < all->info->drawEnd)
		{
			all->info->texY =
					(int) all->info->texPos & (all->info->texHeight - 1);
			all->info->texPos += all->info->step;
			color = ((int *)texture.addr)
					[all->info->texHeight * all->info->texY + 
					all->info->texX];
			my_pixel_put(all, x, y, color);
			y++;
		}

		
		all->info->zBuffer[x] = all->info->perpWallDist;
		//perpendicular distance is used 
// нам нельзся использовать variable length array. поэтому надо замоллочить 
		
		x++;
	}
	sprites(all, all->s);
//	for(int i = 0; i < numSprites; i++) ------- кусок кода для уточнения
//	{
//		spriteOrder[i] = i;
//		spriteDistance[i] = ((info->posX - sprite[i].x) * (info->posX - sprite[i].x) + (info->posY - sprite[i].y) * (info->posY - sprite[i].y)); //sqrt not taken, unneeded
//	}
//		double spriteOrder, double spriteDistance - закинуть в структуру
//		int *spriteOrder = malloc(numSprites * sizeof(int));
//		double *spriteDistance = malloc(numSprites * sizeof(double));
//		все переменные можно закинуть в новую структуру, созданную под спрайты
	mlx_put_image_to_window(all->mlx, all->win->win, all->img->img, 0, 0);
	return (0);
}
