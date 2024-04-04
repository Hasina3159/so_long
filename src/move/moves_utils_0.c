#include "../so_long.h"

int ft_get_player_coord(t_ptr *data)
{
	int		i;
	int		j;
	char	**map;

	if (data == NULL || data->map == NULL)
		return (0);
	map = data->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
			{
				data->player.x = j;
				data->player.y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_data_exit(t_ptr *data, char **map, t_coord *player)
{
	if (data->is_on_exit)
	{
		data->is_on_exit = 0;
		map[player->y][player->x] = EXIT;
		return (1);
	}
	return (0);
}

char	ft_get_data_from_coord(t_ptr *data, int x, int y)
{
	return (data->map[y][x]);
}
int	ft_get_map_y(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}
int	ft_get_map_x(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}