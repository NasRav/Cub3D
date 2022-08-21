#include "../includes/cub3d.h"

static int	argv_num(int argc)
{
	if (argc < 2)
	{
		ft_putendl("Error\nMap isn't submitted");
		return (0);
	}
	if (argc > 3)
	{
		ft_putendl("Error\nToo many arguments!\n");
		return (0);
	}
	return (1);
}

static int	check_ext(char *map)
{
	char	*extension;

	if (!map)
		return (0);
	if (ft_strlen(map) < 5)
		return (0);
	extension = ft_strchr(map, '.');
	if (!extension)
		return (0);
	if (ft_strlen(++extension) > 3)
		return (0);
	if (ft_strncmp("cub", extension, 3) == 0)
		return (1);
	return (0);
}

int	argv_check(int argc, char **argv)
{
	if (argv_num(argc) == 0)
		return (0);
	if (argc > 1)
	{
		if (check_ext(argv[1]) == 0)
			error_handler(5, 0);
		if (argc == 3)
		{
			if ((ft_strlen(argv[2]) != 6))
				error_handler(5, 1);
			if (ft_strncmp("--save", argv[2], 6) != 0)
				error_handler(5, 1);
		}
	}
	return (1);
}
