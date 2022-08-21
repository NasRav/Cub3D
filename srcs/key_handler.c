#include "../includes/cub3d.h"

static void	rotation_rule(t_all *all, float speed)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = all->plr->dir_x;
	all->plr->dir_x = all->plr->dir_x * cos(speed) - all->plr->dir_y * \
		sin(speed);
	all->plr->dir_y = old_dir_x * sin(speed) + all->plr->dir_y * cos(speed);
	old_plane_x = all->plr->plane_x;
	all->plr->plane_x = all->plr->plane_x * cos(speed) - all->plr->plane_y * \
		sin(speed);
	all->plr->plane_y = old_plane_x * sin(speed) + all->plr->plane_y * \
		cos(speed);
}

static void	rotate(t_all *all, int key)
{
	float	speed;

	speed = 0.1;
	if (key == R_RIGHT)
		rotation_rule(all, -speed);
	if (key == R_LEFT)
		rotation_rule(all, speed);
}

static void	left_right(t_all *all, int key, float move_speed, float r)
{
	if (key == LEFT)
	{
		if (all->map[(int)(all->plr->player_x - all->plr->dir_y * \
			(move_speed + r))][(int)(all->plr->player_y)] == '0')
			all->plr->player_x -= all->plr->dir_y * move_speed;
		if (all->map[(int)all->plr->player_x][(int)(all->plr->player_y + \
			all->plr->dir_x * (move_speed + r))] == '0')
			all->plr->player_y += all->plr->dir_x * move_speed;
	}
	if (key == RIGHT)
	{
		if (all->map[(int)(all->plr->player_x + all->plr->dir_y * \
			(move_speed + r))][(int)(all->plr->player_y)] == '0')
			all->plr->player_x += all->plr->dir_y * move_speed;
		if (all->map[(int)all->plr->player_x][(int)(all->plr->player_y - \
			all->plr->dir_x * (move_speed + r))] == '0')
			all->plr->player_y -= all->plr->dir_x * move_speed;
	}
}

static void	forward_back(t_all *all, int key, float move_speed, float r)
{
	if (key == UP)
	{
		if (all->map[(int)(all->plr->player_x + all->plr->dir_x * \
			(move_speed + r))][(int)(all->plr->player_y)] == '0')
			all->plr->player_x += all->plr->dir_x * move_speed;
		if (all->map[(int)(all->plr->player_x)][(int)(all->plr->player_y + \
			all->plr->dir_y * (move_speed + r))] == '0')
			all->plr->player_y += all->plr->dir_y * move_speed;
	}
	if (key == DOWN)
	{
		if (all->map[(int)(all->plr->player_x - all->plr->dir_x * \
			(move_speed + 0.01))][(int)(all->plr->player_y)] == '0')
			all->plr->player_x -= all->plr->dir_x * move_speed;
		if (all->map[(int)all->plr->player_x][(int)(all->plr->player_y - \
			all->plr->dir_y * (move_speed + 0.01))] == '0')
			all->plr->player_y -= all->plr->dir_y * move_speed;
	}
}

int	key_press(int key, t_all *all)
{
	float	move_speed;
	float	r;

	r = 0.3;
	move_speed = 0.15;
	if (key == UP || key == DOWN)
		forward_back(all, key, move_speed, r);
	if (key == RIGHT || key == LEFT)
		left_right(all, key, move_speed, r);
	if (key == R_LEFT || key == R_RIGHT)
		rotate(all, key);
	if (key == ESC)
		exit(0);
	draw_all(all);
	return (0);
}
