#include "../includes/cub3d.h"

static void	check_type(t_params *params, int type)
{
	if (type == 1)
		if (params->c_floor != -1)
			error_handler(3, 3);
	if (type == 2)
		if (params->c_celling != -1)
			error_handler(3, 3);
}

static int	rgb_len(char *s)
{
	int	len;

	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	if (len == 3)
	{
		if (ft_atoi(s) > 255)
			error_handler(3, 4);
	}
	if (len > 3)
		error_handler(3, 4);
	return (len);
}

static int	check_if_rgb(char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (s[i])
	{
		tmp = s[i];
		while (*tmp)
		{
			if (ft_isdigit(*tmp) == 0)
				error_handler(3, 4);
			tmp++;
		}
		i++;
	}
	return (i);
}

static void	check_rgb(char **rgb)
{
	int	i;

	i = 0;
	if (check_if_rgb(rgb) == 3)
	{
		while (rgb[i])
		{
			rgb_len(rgb[i]);
			i++;
		}
	}
	else
		error_handler(3, 4);
}

void	get_color(char *s, t_params *params, int type)
{
	char	**rgb;
	int		i;

	i = 0;
	rgb = NULL;
	check_type(params, type);
	skip_whitespaces(&s);
	rgb = ft_split(s, ',');
	check_rgb(rgb);
	if (type == 1)
		params->c_floor = create_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), \
			ft_atoi(rgb[2]));
	if (type == 2)
		params->c_celling = create_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), \
			ft_atoi(rgb[2]));
	while (i < 3)
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}
