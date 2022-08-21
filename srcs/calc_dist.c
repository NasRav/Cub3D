#include "../includes/cub3d.h"

float	calc_dist(float expr)
{
	float	ret;

	if (expr == 0)
		ret = 1;
	else
		ret = fabs(1 / expr);
	return (ret);
}
