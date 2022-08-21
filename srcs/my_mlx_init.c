#include "../includes/cub3d.h"

void	check_screen_size(t_all *all)
{
	int	r_h;
	int	r_w;

	all->win->width = all->params->res_width;
	all->win->height = all->params->res_height;
	mlx_get_screen_size(all->win->mlx, &r_w, &r_h);
	if (all->params->res_width > r_w)
		all->win->width = r_w;
	if (all->params->res_height > r_h)
		all->win->height = r_h;
}

void	my_mlx_init(t_all *all)
{
	all->win = (t_vars *)malloc(sizeof(t_vars));
	if (!all->win)
		error_handler(3, 0);
	all->win->mlx = mlx_init();
	check_screen_size(all);
}
