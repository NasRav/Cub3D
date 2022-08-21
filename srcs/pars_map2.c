#include "../includes/cub3d.h"

void	check_valid(t_params *param, int i, int j, char dir_plr)
{
	dir_plr = '\0';
	if (!param->map)
		error_handler(3, 5);
	while (param->map[i] && i < param->map_h)
	{
		j = 0;
		while (param->map[i][j])
		{
			if (ft_strchr(" WSEN012", param->map[i][j]) == NULL)
				error_handler(3, 5);
			else if (param->map[i][j] == 'W' || param->map[i][j] == 'S' || \
				param->map[i][j] == 'E' || param->map[i][j] == 'N')
			{
				if (dir_plr == '\0')
					dir_plr = param->map[i][j];
				else
					error_handler(3, 3);
			}
			j++;
		}
		i++;
	}
	if (dir_plr == '\0')
		error_handler(3, 8);
}

void	first_last(t_params *param, int i)
{
	while (param->map[0][i])
	{
		if (param->map[0][i] == '1' || param->map[0][i] == ' ')
		{
			i++;
		}
		else
		{
			error_handler(3, 5);
		}
	}
	i = 0;
	while (param->map[param->map_h - 1][i])
	{
		if (param->map[param->map_h - 1][i] == ' ' || \
			param->map[param->map_h - 1][i] == '1')
		{
			i++;
		}
		else
		{
			error_handler(3, 5);
		}
	}
}

void	check_bound(t_params *param)
{
	int	i;

	i = 0;
	first_last(param, i);
	while (param->map[i][0] && i < param->map_h - 1)
	{
		if (param->map[i][0] == ' ' || param->map[i][0] == '1')
			i++;
		else
			error_handler(3, 5);
	}
	i = 0;
	while (param->map[i] && i < param->map_h)
	{
		if (param->map[i][ft_strlen(param->map[i]) - 1] == ' ' || \
			param->map[i][ft_strlen(param->map[i]) - 1] == '1')
			i++;
		else
			error_handler(3, 5);
	}
}

void	to_zero(t_params *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map[i] && i < param->map_h - 1)
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == '+')
				param->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	flood(t_params *param)
{
	int		i;
	int		j;
	char	**new_map;

	i = 1;
	max_width(param);
	new_map = copy_map(param);
	while (new_map[i] && i < param->map_h + 2)
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] == '0' || new_map[i][j] == '2')
			{
				flood_fill(new_map, param, j, i);
			}
			j++;
		}
		i++;
	}
	free_new_map(param, new_map);
}
