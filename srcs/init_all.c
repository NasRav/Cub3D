#include "../includes/cub3d.h"

void	sprites_init(t_all *all)
{
	all->raycast = (t_raycast *)malloc(sizeof(t_raycast));
	if (!all->raycast)
		error_handler(3, 0);
	all->raycast->num_sprites = all->params->count_spr;
	sprites_to_array(all);
}

static void	dir_init_w(t_all *all)
{
	all->plr->dir_x = 0;
	all->plr->dir_y = -1.0;
	all->plr->plane_x = -0.66;
	all->plr->plane_y = 0;
}

static void	dir_init(t_all *all)
{
	if (all->params->dir == 'N')
	{
		all->plr->dir_x = -1;
		all->plr->dir_y = 0;
		all->plr->plane_x = 0;
		all->plr->plane_y = 0.66;
	}
	else if (all->params->dir == 'S')
	{
		all->plr->dir_x = 1.0;
		all->plr->dir_y = 0;
		all->plr->plane_y = -0.66;
		all->plr->plane_x = 0;
	}
	else if (all->params->dir == 'E')
	{
		all->plr->dir_x = 0;
		all->plr->dir_y = 1;
		all->plr->plane_x = 0.66;
		all->plr->plane_y = 0;
	}
	else if (all->params->dir == 'W')
	{
		dir_init_w(all);
	}
}

void	my_plr_init(t_all *all)
{
	all->plr = (t_plr *)malloc(sizeof(t_plr));
	if (!all->plr)
		error_handler(3, 0);
	all->plr->player_x = all->params->f_plr_y;
	all->plr->player_y = all->params->f_plr_x;
	dir_init(all);
	all->map = all->params->map;
	all->plr->buf = (float *)malloc((all->win->width + 1) * \
		sizeof(float));
	if (!all->plr->buf)
		error_handler(3, 0);
}

void	start_init(t_all *all, int x)
{
	t_plr	*plr;

	plr = all->plr;
	all->screen_save = 0;
	plr->camera_x = 2 * x / (float)all->win->width - 1;
	plr->ray_dir_x = plr->dir_x + plr->plane_x * plr->camera_x;
	plr->ray_dir_y = plr->dir_y + plr->plane_y * plr->camera_x;
	plr->map_x = (int)plr->player_x;
	plr->map_y = (int)plr->player_y;
	if (plr->ray_dir_y == 0)
		plr->dlt_dist_x = 0;
	else
		plr->dlt_dist_x = calc_dist(plr->ray_dir_x);
	if (plr->ray_dir_x == 0)
		plr->dlt_dist_y = 0;
	else
		plr->dlt_dist_y = calc_dist(plr->ray_dir_y);
	all->plr->hit = 0;
	plr->perp_wall_dist = 0;
}
