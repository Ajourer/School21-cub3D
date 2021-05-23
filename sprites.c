#include "cub.h"

void sprites(t_all *all, t_sprites *s)
{
	int i;
	
	i =0;
	
	s->sprite_order = malloc(all->num_spr * sizeof(int));
	s->sprite_distance = malloc(all->num_spr * sizeof(double));
	while (i++ < all->num_spr)
	{
		s->sprite_order[i] = i;
		s->sprite_distance[i] = ((all->info->pos_x - all->spr[i].x) *
				(all->info->pos_x - all->spr[i].x) + (all->info->pos_y - 
				all->spr[i].y) * (all->info->pos_y - all->spr[i].y));
	}
	//эта функция сортировки еще не написана
	//sort_sprites(s->sprite_order, s->sprite_distance, all->num_spr);
	
	//делаем проекцию и рисуем ее
	i = 0;
	while (i++ < all->num_spr)
	{
		s->sprite_x = all->spr[s->sprite_order[i]].x - all->info->pos_x;
		s->sprite_y = all->spr[s->sprite_order[i]].y - all->info->pos_y;
		
		s->inv_det = 1.0 / (all->info->plane_x * all->info->dir_y - 
				all->info->dir_x * all->info->plane_y);
		
		s->transform_x = s->inv_det * (all->info->dir_y * s->sprite_x -
				all->info->dir_x * s->sprite_y);
		s->transform_y = s->inv_det * (-all->info->plane_y * s->sprite_x +
				all->info->plane_x * s->sprite_y);
		
//		s->sprite_screen_x =
		
	}
}