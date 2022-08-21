#include "libft.h"

void	ft_lstdel(void *content)
{
	if (content)
		free(content);
}
