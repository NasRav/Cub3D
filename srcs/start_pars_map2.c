#include "../includes/cub3d.h"

void	find_plr(char **map, t_params *params, int i)
{
	char	*dir;
	int		j;

	while (map[i])
	{
		j = 0;
		while (i < params->map_h && map[i][j])
		{
			dir = ft_strchr("NSEW", map[i][j]);
			if (dir != NULL)
			{
				params->i_plr_x = j;
				params->i_plr_y = i;
				params->f_plr_x = j + 0.5;
				params->f_plr_y = i + 0.5;
				map[i][j] = '0';
				if (dir != NULL && params->dir == '\0')
					params->dir = dir[0];
				else if (params->dir != '\0')
					error_handler(3, 7);
			}
			j++;
		}
		i++;
	}
}

void	find_sprites(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	params->count_spr = 0;
	while (i < params->map_h)
	{
		j = 0;
		while (params->map[i][j])
		{
			if (params->map[i][j] == '2')
				params->count_spr++;
			j++;
		}
		i++;
	}
}

t_list	*skip_empty(t_list *list)
{
	char	*s;

	while (list)
	{
		if (list->content)
		{
			s = list->content;
			while (*s == ' ')
				s++;
			if (*s != '\0')
				break ;
		}
		list = list->next;
	}
	return (list);
}
