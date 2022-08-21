#include "../includes/cub3d.h"

void	flood_fill(char **map, t_params *params, int x, int y)
{
	char	new_color;

	new_color = '+';
	if (x > 0 && x < params->map_w && y > 0 && y < params->map_h + 2 && \
		(map[y][x] == ' ' || map[y][x] == '-'))
		error_handler(3, 6);
	if ((x >= 0 && x < params->map_w) && (y >= 0 && y < params->map_h) && \
		((map[y][x] == '0' || map[y][x] == '2') && map[y][x] != new_color))
	{
		map[y][x] = new_color;
		flood_fill(map, params, x + 1, y);
		flood_fill(map, params, x - 1, y);
		flood_fill(map, params, x, y + 1);
		flood_fill(map, params, x, y - 1);
	}
}

void	max_width(t_params *param)
{
	int	i;
	int	j;

	i = 0;
	param->map_w = 0;
	while (i < param->map_h && param->map[i])
	{
		j = 0;
		while (param->map[i][j])
			j++;
		if (param->map_w < j)
			param->map_w = j;
		i++;
	}
}

static int	copy_main_map(t_params *params, char **new_map, int i)
{
	int		k;
	char	new_symbol;
	int		j;

	k = 0;
	new_symbol = '-';
	while (k < params->map_h)
	{
		new_map[i] = (char *)ft_calloc(params->map_w + 1, sizeof(char));
		ft_strcpy(new_map[i], params->map[k]);
		if ((int)ft_strlen(params->map[k]) < params->map_w)
		{
			j = ft_strlen(params->map[k]);
			while (j < params->map_w)
			{
				new_map[i][j] = new_symbol;
				j++;
			}
		}
		k++;
		i++;
	}
	return (i);
}

char	**copy_map(t_params *param)
{
	char	**new_map;
	int		i;
	char	new_symbol;

	new_symbol = '-';
	i = 0;
	new_map = (char **)ft_calloc((param->map_h + 3), sizeof(char *));
	new_map[i] = (char *)ft_calloc(param->map_w + 1, sizeof(char));
	ft_memset(new_map[i++], new_symbol, param->map_w);
	i = copy_main_map(param, new_map, i);
	new_map[i] = (char *)ft_calloc(param->map_w + 1, sizeof(char));
	ft_memset(new_map[i], new_symbol, param->map_w);
	return (new_map);
}

void	free_new_map(t_params *param, char **new_map)
{
	int	l;

	l = 0;
	while (l < param->map_h + 2)
	{
		free(new_map[l]);
		l++;
	}
	free(new_map);
}
