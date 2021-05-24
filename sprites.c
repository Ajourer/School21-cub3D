#include "cub.h"

void	sort_sprites(int *sprite_order, double *sprite_distance, int len)
{
	int		i;
	int		j;
	double	dist_perm;
	int		order_perm;
	i = 0;
	while (i < len - 1)
	{
		j = len - 1;
		while (j > i)
		{
			if (sprite_distance[j - 1] < sprite_distance[j])
			{
				dist_perm = sprite_distance[j - 1];
				order_perm = sprite_order[j - 1];
				sprite_distance[j - 1] = sprite_distance[j];
				sprite_distance[j] = dist_perm;
				sprite_order[j - 1] = sprite_order[j];
				sprite_order[j] = order_perm;
			}
			j--;
		}
		i++;
	}
}

void sprites(t_all *all, t_sprites *s)
{
	int i;
	
	i = -1;
	
	while (++i< all->num_spr)
	{
		s->sprite_order[i] = i;
		s->sprite_distance[i] = ((all->info->pos_x - all->spr[i].x) *
				(all->info->pos_x - all->spr[i].x) + (all->info->pos_y - 
				all->spr[i].y) * (all->info->pos_y - all->spr[i].y));
	}
	//эта функция сортировки еще не написана
	sort_sprites(s->sprite_order, s->sprite_distance, all->num_spr);
	
	//делаем проекцию и рисуем ее
	i = -1;
	while (++i < all->num_spr)
	{
		s->sprite_x = all->spr[s->sprite_order[i]].x - all->info->pos_x;
		s->sprite_y = all->spr[s->sprite_order[i]].y - all->info->pos_y;
		
		s->inv_det = 1.0 / (all->info->plane_x * all->info->dir_y - 
				all->info->dir_x * all->info->plane_y);
		
		s->transform_x = s->inv_det * (all->info->dir_y * s->sprite_x -
				all->info->dir_x * s->sprite_y);
		s->transform_y = s->inv_det * (-all->info->plane_y * s->sprite_x +
				all->info->plane_x * s->sprite_y);
		s->sprite_screen_x = (int)((all->win->width / 2) * (1 + s->transform_x /
				s->transform_y));
		
		s->sprite_height = abs((int)(all->win->height / s->transform_y));
		s->draw_start_y = -s->sprite_height / 2 + all->win->height / 2;
		if (s->draw_start_y < 0)
			s->draw_start_y = 0;
		s->draw_end_y = s->sprite_height / 2 + all->win->height / 2;
		if (s->draw_end_y >= all->win->height)
			s->draw_end_y = all->win->height - 1;
		
		s->sprite_width = abs((int)(all->win->height / s->transform_y));
		s->draw_start_x = -s->sprite_width / 2 + s->sprite_screen_x;
		if (s->draw_start_x < 0)
			s->draw_start_x = 0;
		s->draw_end_x = s->sprite_width / 2 + s->sprite_screen_x;
		if (s->draw_end_x >= all->win->width)
			s->draw_end_x = all->win->width - 1;
		
		s->stripe = s->draw_start_x;
		while(s->stripe < s->draw_end_x)
		{
			s->tex_x = (int)(256 * (s->stripe - (-s->sprite_width / 2 +
					s->sprite_screen_x)) * all->info->texWidth /
							s->sprite_width) / 256;
			int y;
			int d;
			
			y = s->draw_start_y;
			if (s->transform_y > 0 && s->stripe > 0 && s->stripe < 
			all->win->width && s->transform_y < all->info->zBuffer[s->stripe])
			{
				while (y < s->draw_end_y)
				{
					d = y * 256 - all->win->height * 128 +
							s->sprite_height * 128;
					s->tex_y = ((d * all->info->texHeight) /
							s->sprite_height) / 256;
					s->color = ((unsigned int *)(all->sp_i->addr))
							[all->info->texWidth * s->tex_y + s->tex_x];
					if ((s->color & 0xFFFFFF) != 0)
						my_pixel_put(all, s->stripe, y, s->color);
					y++;
				}
			}
			s->stripe++;
		}
	}
}
