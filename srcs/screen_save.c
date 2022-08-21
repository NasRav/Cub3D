#include "../includes/cub3d.h"

static void	init(t_all *all)
{
	my_mlx_init(all);
	all->win->win = mlx_new_window(all->win->mlx, all->win->width, \
		all->win->height, "cub3D");
	if (!all->win->win)
		error_handler(3, 0);
	my_image_init(all);
	my_plr_init(all);
	sprites_init(all);
	read_text(all);
	draw_all(all);
}

static void	bmp_header(t_all *all, int fd)
{
	unsigned char	*file_header;
	int				file_size;

	file_header = (unsigned char *)malloc(14 * sizeof(unsigned char));
	ft_bzero(file_header, 14);
	file_size = 14 + 40 + (4 * all->win->width * all->win->height);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	write(fd, file_header, 14);
	free(file_header);
}

static void	bmp_info(t_all *all, int fd)
{
	unsigned char	*file_header;

	file_header = (unsigned char *)malloc(40 * sizeof(unsigned char));
	ft_bzero(file_header, 40);
	file_header[0] = (unsigned char)(40);
	file_header[4] = (unsigned char)(all->win->width);
	file_header[5] = (unsigned char)(all->win->width >> 8);
	file_header[6] = (unsigned char)(all->win->width >> 16);
	file_header[7] = (unsigned char)(all->win->width >> 24);
	file_header[8] = (unsigned char)(all->win->height);
	file_header[9] = (unsigned char)(all->win->height >> 8);
	file_header[10] = (unsigned char)(all->win->height >> 16);
	file_header[11] = (unsigned char)(all->win->height >> 24);
	file_header[12] = (unsigned char)(1);
	file_header[14] = (unsigned char)(4 * 8);
	write(fd, file_header, 40);
	free(file_header);
}

static void	make_bmp(t_all *all)
{
	int	y;
	int	line_length;

	line_length = all->win->width * all->img->bpp / 8;
	y = all->win->height;
	while (0 <= y)
	{
		write(all->fd, (unsigned char *)(all->img->addr + \
			y * all->img->line_length), line_length);
		y--;
	}
}

void	screen_save(t_all *all)
{
	all->fd = open("image.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	init(all);
	bmp_header(all, all->fd);
	bmp_info(all, all->fd);
	make_bmp(all);
	close(all->fd);
	exit(0);
}
