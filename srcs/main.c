#include "../includes/cub3d.h"

static int	exit_0(void)
{
	exit(0);
}

static int	start(int argc, char **argv)
{
	t_all	*all;

	all = pars_all(argv[1]);
	if (!all)
		error_handler(3, 0);
	if (argc == 3)
		screen_save(all);
	my_mlx_init(all);
	read_text(all);
	all->win->win = mlx_new_window(all->win->mlx, all->win->width, \
		all->win->height, "cub3D");
	if (!all->win->win)
		error_handler(4, 0);
	my_image_init(all);
	game(all, argc);
	mlx_hook(all->win->win, 17, (1L << 0), &exit_0, all);
	mlx_hook(all->win->win, 2, (1L << 0), &key_press, all);
	mlx_loop(all->win->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argv_check(argc, argv) == 0)
		error_handler(5, 0);
	if (start(argc, argv) == 0)
		return (0);
}
