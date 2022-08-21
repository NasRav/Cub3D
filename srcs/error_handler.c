#include "../includes/cub3d.h"

static void	map_params_error(int code)
{
	if (code == -1)
		ft_putendl("Error\nMinilibx error");
	if (code == 0)
		ft_putendl("Error\nmMemory allocation failed");
	else if (code == 1)
		ft_putendl("Error\nResolution is incorrect!");
	else if (code == 2)
		ft_putendl("Error\nInvalid file or extension");
	else if (code == 3)
		ft_putendl("Error\nSome data has duplicates");
	else if (code == 4)
		ft_putendl("Error\nColor is incorrect");
	else if (code == 5)
		ft_putendl("Error\nFile format incorrect");
	else if (code == 6)
		ft_putendl("Error\nInvalid map: remove spaces");
	else if (code == 7)
		ft_putendl("Error\nNeed more data");
	else if (code == 8)
		ft_putendl("Error\nPlayer not found");
}

void	error_handler(int type_error, int error_code)
{
	if (type_error == 1)
		ft_putendl("Error\nFailed to open file!");
	if (type_error == 2)
		ft_putendl("Error\nCan't read file");
	if (type_error == 3)
		map_params_error(error_code);
	if (type_error == 4)
		ft_putendl("Error\nMinilibx failed");
	if (type_error == 5 && error_code == 0)
		ft_putendl("Error\nArguments are incorrect");
	if (type_error == 5 && error_code == 1)
		ft_putendl("Error\nInvalid third argument");
	exit(2);
}
