#include "../includes/cub3d.h"

int	struct_is_full(t_params *params)
{
	return (params->res_width != -1 && params->res_height != -1 && \
		params->text_no != NULL && params->text_so != NULL && \
		params->text_we != NULL && params->text_ea != NULL && \
		params->text_spr != NULL && params->c_floor != -1 && \
		params->c_celling != -1);
}

void	init_all(t_params *params)
{
	params->res_width = -1;
	params->res_height = -1;
	params->text_no = NULL;
	params->text_so = NULL;
	params->text_we = NULL;
	params->text_ea = NULL;
	params->text_spr = NULL;
	params->c_floor = -1;
	params->c_celling = -1;
	params->dir = '\0';
}

t_all	*pars_all(char *filename)
{
	int		fd;
	t_list	*file;
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		error_handler(3, 0);
	fd = open_file(filename);
	if (fd < 0)
		error_handler(1, 0);
	file = read_file(fd);
	if (!file)
		error_handler(2, 0);
	all->params = pars_file(&file);
	if (!all->params)
		error_handler(3, 0);
	return (all);
}
