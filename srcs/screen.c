#include "../cub.h"

void int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

void set_bmp(t_all *all, int file_size, int fd)
{
	unsigned char bmp[54];

	ft_bzero(bmp, 54);
	bmp[0] = (unsigned char)('B');
	bmp[1] = (unsigned char)('M');
	int_to_char(file_size, bmp + 2);
	bmp[10] = (unsigned char)(54);
	bmp[14] = (unsigned char)(40);
	int_to_char(all->win->width, bmp + 18);
	int_to_char(all->win->height, bmp + 22);
	bmp[26] = (unsigned char)(1);
	bmp[28] = (unsigned char)(24);
	write(fd, bmp, 54);
}

void get_pixel(t_all *all, int fd)
{
	int i;
	int j;
	int	color;
	
	i = all->win->height - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < all->win->width)
		{
			color = *(int *)(all->img->addr + (i * all->img->ll + j * 
					(all->img->bpp / 8)));
			write(fd, &color, 3);
		}
		i--;
	}
}

void screen(t_all *all)
{
	int fd;
	int size;
	
	while (all->win->width % 4 != 0)
		all->win->width--;
	size = 54 + (4 * all->win->height * all->win->width);
	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (!fd)
		error(5, all);
	set_bmp(all, size, fd);
	get_pixel(all, fd);
	close(fd);
	exit(0);
}