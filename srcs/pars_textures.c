#include "../includes/cub3d.h"

static void	check_sides(t_params *params, int side)
{
	if (side == 1)
		if (params->text_no != NULL)
			error_handler(3, 3);
	if (side == 2)
		if (params->text_so != NULL)
			error_handler(3, 3);
	if (side == 3)
		if (params->text_we != NULL)
			error_handler(3, 3);
	if (side == 4)
		if (params->text_ea != NULL)
			error_handler(3, 3);
	if (side == 6)
		if (params->text_spr != NULL)
			error_handler(3, 3);
}

static void	check_xpm_ext(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	if (len < 5)
		error_handler(3, 2);
	if (ft_strncmp(".xpm", &s[len - 4], 4) != 0)
		error_handler(3, 2);
}

void	check_trash(char *s)
{
	while (*s)
	{
		if (*s != ' ')
		{
			error_handler(3, 5);
		}
		s++;
	}
}

void	pars_textures(char *s, t_params *params, int side)
{
	int	len;

	len = 0;
	check_sides(params, side);
	skip_whitespaces(&s);
	check_xpm_ext(s);
	while (s[len] && s[len] != ' ')
		len++;
	if (s[len] != '\0')
		error_handler(3, 5);
	if (side == 1)
		params->text_no = ft_substr(s, 0, len);
	else if (side == 2)
		params->text_so = ft_substr(s, 0, len);
	else if (side == 3)
		params->text_we = ft_substr(s, 0, len);
	else if (side == 4)
		params->text_ea = ft_substr(s, 0, len);
	else if (side == 6)
		params->text_spr = ft_substr(s, 0, len);
}
