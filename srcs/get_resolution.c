#include "../includes/cub3d.h"

static int	res_w_h(char *s, int len)
{
	int		nbr;
	char	*str;
	int		i;

	str = s;
	i = 0;
	if (len > 6)
		return (10000);
	while (str[i] == '0')
		i++;
	nbr = ft_atoi(s);
	if (nbr == 0)
		error_handler(3, 1);
	return (nbr);
}

void	skip_whitespaces(char **s)
{
	while (**s == ' ' && **s)
		(*s)++;
}

static int	lennbr(char *s)
{
	int	len;

	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	return (len);
}

static void	check_valid_res(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != ' ')
			error_handler(3, 1);
		s++;
	}
}

void	get_resolution(char *s, t_params *params, int len)
{
	check_valid_res(s);
	if (params->res_height != -1 && params->res_width != -1)
		error_handler(3, 1);
	skip_whitespaces(&s);
	len = lennbr(&s[len]);
	if (len < 7)
	{
		if (ft_isdigit(*s))
			params->res_width = res_w_h(s, len);
	}
	else
		params->res_width = 10000;
	while (ft_isdigit(*s))
		s++;
	skip_whitespaces(&s);
	len = lennbr(s);
	if (len < 7)
	{
		if (ft_isdigit(*s))
			params->res_height = res_w_h(s, len);
	}
	else
		params->res_height = 10000;
	if (s[len] != '\0')
		error_handler(3, 1);
}
