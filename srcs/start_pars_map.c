#include "../includes/cub3d.h"

int	str_is_empty(char *line)
{
	if (!*line)
		return (1);
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (0);
}

static void	map_last(t_list *map)
{
	int	count;

	count = 0;
	if (map)
	{
		while (map)
		{
			map = map->next;
			count++;
		}
	}
	else
		return ;
	if (count > 1 || count == 0)
		error_handler(3, 5);
}

static void	create_map(t_params *params, t_list *tmp, int i)
{
	t_list	*map_list;

	map_list = tmp;
	params->map_h = 0;
	while (tmp)
	{
		if (tmp->content)
		{
			tmp = tmp->next;
			params->map_h++;
			if (!tmp || str_is_empty(tmp->content))
				break ;
		}
		else
			break ;
	}
	map_last(tmp);
	params->map = (char **)ft_calloc(params->map_h + 1, sizeof(char *));
	while (map_list)
	{
		params->map[i] = ft_strdup(map_list->content);
		map_list = map_list->next;
		i++;
	}
}

void	init_map_params(t_list *tmp, t_params *params)
{
	tmp = skip_empty(tmp);
	create_map(params, tmp, 0);
	check_valid(params, 0, 0, '\0');
	check_bound(params);
	find_plr(params->map, params, 0);
	flood(params);
	find_sprites(params);
	to_zero(params);
}
