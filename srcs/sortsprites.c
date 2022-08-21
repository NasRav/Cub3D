#include "../includes/cub3d.h"

void	sprites_to_array(t_all *all)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	all->raycast->sprites = malloc(all->params->count_spr * sizeof(t_sprite));
	if (!all->raycast->sprites)
		error_handler(3, 0);
	while (i < all->params->map_h && all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
			{
				all->map[i][j] = 's';
				all->raycast->sprites[k].x = (float)i;
				all->raycast->sprites[k].y = (float)j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_sprite *sprite, int count)
{
	int			i;
	int			sorted;
	t_sprite	tmp;

	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < count - 1)
		{
			if (sprite[i].dist < sprite[i + 1].dist)
			{
				tmp = sprite[i];
				sprite[i] = sprite[i + 1];
				sprite[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}
