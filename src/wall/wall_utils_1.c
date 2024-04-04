#include "../so_long.h"

int ft_wall_has_ud(char **map, int x, int y)
{
	if (ft_wall_has_u(map, x, y) && ft_wall_has_d(map, x, y))
        return (1);
    return (0);
}

int ft_wall_has_lr(char **map, int x, int y)
{
	if (ft_wall_has_l(map, x, y) && ft_wall_has_r(map, x, y))
        return (1);
    return (0);
}

int ft_wall_ud(char **map, int x, int y)
{
	if (ft_wall_has_u(map, x, y) || ft_wall_has_d(map, x, y))
        return (1);
    return (0);
}

int ft_wall_lr(char **map, int x, int y)
{
	if (ft_wall_has_l(map, x, y) || ft_wall_has_r(map, x, y))
        return (1);
    return (0);
}