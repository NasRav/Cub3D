#include "../includes/cub3d.h"

static void	load_image(t_data *texture, t_all *all, char *filename)
{
	if (!texture)
		error_handler(3, 0);
	texture->img = mlx_xpm_file_to_image(all->win->mlx, filename, \
		&texture->width, &texture->height);
	if (texture->img)
		texture->addr = (char *)mlx_get_data_addr(texture->img, \
			&texture->bpp, &texture->line_length, &texture->endian);
	else
		error_handler(4, -1);
	free(filename);
}

void	read_text(t_all *all)
{
	int	x;

	x = 1;
	all->so = (t_data *)malloc(x * sizeof(t_data));
	all->no = (t_data *)malloc(x * sizeof(t_data));
	all->we = (t_data *)malloc(x * sizeof(t_data));
	all->ea = (t_data *)malloc(x * sizeof(t_data));
	all->spr = (t_data *)malloc(x * sizeof(t_data));
	if (!(all->so && all->no && all->we && all->ea && all->spr))
	{
		error_handler(3, 0);
	}
	load_image((all->so), all, all->params->text_so);
	load_image((all->no), all, all->params->text_no);
	load_image((all->we), all, all->params->text_we);
	load_image((all->ea), all, all->params->text_ea);
	load_image((all->spr), all, all->params->text_spr);
}
