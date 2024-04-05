#include "../so_long.h"

int ft_check_u(char **map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (x < ft_get_map_x(map))
	{
		if (map[y][x] != WALL)
			return (0);
		x++;
	}
	return (1);
}

int ft_check_d(char **map)
{
	int x;
	int	y;

	x = 0;
	y = ft_get_map_y(map) - 1;
	while (x < ft_get_map_x(map))
	{
		if (map[y][x] != WALL)
			return (0);
		x++;
	}
	return (1);
}

int ft_check_l(char **map)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < ft_get_map_y(map))
	{
		if (map[y][x] != WALL)
			return (0);
		x++;
	}
	return (1);
}

int ft_check_r(char **map)
{
	int x;
	int	y;

	x = ft_get_map_x(map) - 1;
	y = 0;
	while (y < ft_get_map_y(map))
	{
		if (map[y][x] != WALL)
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_border(char **map)
{
	if (!ft_check_u(map) || !ft_check_d(map))
		return (0);
	if (!ft_check_l(map) || !ft_check_r(map))
		return (0);
	return (1);
}