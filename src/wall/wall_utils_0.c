#include "../so_long.h"

int ft_wall_has_u(char **map, int x, int y)
{
	if (y == 0 || y == 1)
		return (0);
	if (map[y - 1][x] == WALL)
		return (1);
	return (0);
}

int ft_wall_has_d(char **map, int x, int y)
{
	if (y == ft_get_map_y(map) - 1 || y == ft_get_map_y(map) - 2)
		return (0);
	if (map[y + 1][x] == WALL)
		return (1);
	return (0);
}

int ft_wall_has_l(char **map, int x, int y)
{
	if (x == 0 || x == 1)
		return (0);
	if (map[y][x - 1] == WALL)
		return (1);
	return (0);
}

int ft_wall_has_r(char **map, int x, int y)
{
	if (y == ft_get_map_x(map) - 1 || y == ft_get_map_x(map) - 2)
		return (0);
	if (map[y][x + 1] == WALL)
		return (1);
	return (0);
}

