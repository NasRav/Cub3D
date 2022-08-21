#include "../includes/cub3d.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		fd = -1;
	}
	return (fd);
}

t_list	*read_file(int fd)
{
	t_list	*head;
	char	*line;
	int		i;

	head = NULL;
	line = NULL;
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		i = get_next_line(fd, &line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	if (i < 0)
	{
		ft_lstclear(&head, ft_lstdel);
		error_handler(2, 0);
	}
	return (head);
}
