#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>

void calculation(t_rayCast *rc, t_window *win, t_info *inf, t_texture *tex)
{
	int x;

	x = 0;

	while (x < win->width)
	{
		printf("%d\n", 1);
		rc->cameraX = 2 * x / (double)win->width - 1;
		rc->rayDirX = inf->dirX + inf->planeX * rc->cameraX;
		rc->rayDirY = inf->dirY + inf->planeY * rc->cameraX;
		rc->mapX = (int)inf->posX;
		rc->mapY = (int)inf->posY;
		rc->deltaDistX = fabs(1 / rc->rayDirX);
		rc->deltaDistY = fabs(1 / rc->rayDirY);
		rc->hit = 0;

		if(rc->rayDirX < 0)
		{
			rc->stepX = -1;
			rc->sideDistX = (inf->posX - rc->mapX) * rc->deltaDistX;
		}
		else
		{
			rc->stepX = 1;
			rc->sideDistX = (rc->mapX + 1.0 - inf->posX) * rc->deltaDistX;
		}
		if(rc->rayDirY < 0)
		{
			rc->stepY = -1;
			rc->sideDistY = (inf->posY - rc->mapY) * rc->deltaDistY;
		}
		else
		{
			rc->stepY = 1;
			rc->sideDistY = (rc->mapY + 1.0 - inf->posY) * rc->deltaDistY;
		}

		while (rc->hit == 0)
		{
			if(rc->sideDistX < rc->sideDistY)
			{
				rc->sideDistX += rc->deltaDistX;
				rc->mapX += rc->stepX;
				rc->side = 0;
			}
			else
			{
				rc->sideDistY += rc->deltaDistY;
				rc->mapY += rc->stepY;
				rc->side = 1;
			}
			rc->hit = 1;
		}

		if(rc->side == 0)
			rc->perpWallDist = (rc->mapX - inf->posX + (1 - rc->stepX) / 2) /
					rc->rayDirX;
		else
			rc->perpWallDist = (rc->mapY - inf->posY + (1 - rc->stepY) / 2) /
					rc->rayDirY;

		rc->lineHeight = (int)(win->height / rc->perpWallDist);

		rc->drawStart = -rc->lineHeight / 2 + win->height / 2;
		if(rc->drawStart < 0)
			rc->drawStart = 0;
		rc->drawEnd = rc->lineHeight / 2 + win->height / 2;
		if(rc->drawEnd >= win->height)
			rc->drawEnd = win->height - 1;

		if(rc->side == 0)
			rc->wallX = inf->posY + rc->perpWallDist * rc->rayDirY;
		else
			rc->wallX = inf->posX + rc->perpWallDist * rc->rayDirX;
		rc->wallX -= floor((rc->wallX));

		tex->texWidth = 64;
		tex->texHeight = 64;
		rc->texX = (int)(rc->wallX * (double)tex->texWidth);
		if(rc->side == 0 && rc->rayDirX > 0)
			rc->texX = tex->texWidth - rc->texX - 1;
		if(rc->side == 1 && rc->rayDirY < 0)
			rc->texX = tex->texWidth - rc->texX - 1;

		rc->step = 1.0 * tex->texHeight / rc->lineHeight;

		rc->texPos = (rc->drawStart - win->height / 2 + rc->lineHeight / 2) *
				rc->step;
		int y;
		int color;

		y = rc->drawStart;
		while (y < rc->drawEnd)
		{
			rc->texY = (int)rc->texPos & (tex->texHeight - 1);
			rc->texPos += rc->step;
			//color = ((int*)(inf->texture))
			//		[tex->texHeight * rc->texY + rc->texX];
			y++;
		}

		x++;
	}
}

int main(void)
{
	t_texture tex;
	t_info inf;
	t_window win;
	t_rayCast rc;
	win.width = 800;
	win.height = 600;

	calculation(&rc, &win, &inf, &tex);
	return (0);
}

