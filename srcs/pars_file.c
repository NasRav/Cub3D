#include "../includes/cub3d.h"

void	check_identifier(char *line, t_params *params)
{
	if (line)
	{
		if (ft_strncmp("R ", line, 2) == 0)
			get_resolution(line + 2, params, 0);
		else if (ft_strncmp("NO ", line, 3) == 0)
			pars_textures(line + 3, params, 1);
		else if (ft_strncmp("SO ", line, 3) == 0)
			pars_textures(line + 3, params, 2);
		else if (ft_strncmp("WE ", line, 3) == 0)
			pars_textures(line + 3, params, 3);
		else if (ft_strncmp("EA ", line, 3) == 0)
			pars_textures(line + 3, params, 4);
		else if (ft_strncmp("S ", line, 2) == 0)
			pars_textures(line + 2, params, 6);
		else if (ft_strncmp("F ", line, 2) == 0)
			get_color(line + 2, params, 1);
		else if (ft_strncmp("C ", line, 2) == 0)
			get_color(line + 2, params, 2);
		else
			check_trash(line);
	}
}

int	params_line(char *s, t_params *params)
{
	if (!struct_is_full(params))
		check_identifier(s, params);
	else
		return (1);
	return (0);
}

static t_params	*pars_lines(t_list **head)
{
	t_params	*params;
	t_list		*tmp;

	tmp = *head;
	params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		error_handler(3, 0);
	init_all(params);
	while (tmp)
	{
		if (params_line(tmp->content, params) == 0)
			tmp = tmp->next;
		else
			break ;
	}
	if (!struct_is_full(params))
	{
		ft_lstclear(head, ft_lstdel);
		error_handler(3, 7);
	}
	init_map_params(tmp, params);
	return (params);
}

t_params	*pars_file(t_list **file)
{
	t_params	*params;

	params = pars_lines(file);
	ft_lstclear(file, ft_lstdel);
	return (params);
}
