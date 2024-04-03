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

char	ft_get_data_from_coord(t_ptr *data, int x, int y)
{
	return (data->map[y][x]);
}

int ft_go_up(t_ptr *data)
{
	t_coord	*player;
	char	**map;
	char	up;

	ft_get_player_coord(data);
	player = &data->player;
	map = data->map;
	if (player->y == 0)
		return (0);
	up = ft_get_data_from_coord(data, player->x, player->y - 1);
	if (up == WALL)
	{
		printf("0");
		return (0);
	}
	else if (up == EXIT)
	{
		data->is_on_exit = 1;
		map[player->y][player->x] = VOID;
		printf("1");
	}
	else
	{
		if (data->is_on_exit)
		{
			data->is_on_exit = 0;
			map[player->y][player->x] = EXIT;
			printf("2");
		}
		else
		{
			map[player->y][player->x] = VOID;
			printf("3");
		}
		printf("4");
	}
	printf("5");
	map[player->y - 1][player->x] = PLAYER;
	return (1);
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

int ft_go_down(t_ptr *data)
{
	t_coord	*player;
	char	**map;
	char	up;

	ft_get_player_coord(data);
	player = &data->player;
	map = data->map;
	if (player->y >= ft_get_map_y(map) - 1)
		return (0);
	up = ft_get_data_from_coord(data, player->x, player->y + 1);
	if (up == WALL)
	{
		printf("0");
		return (0);
	}
	else if (up == EXIT)
	{
		data->is_on_exit = 1;
		map[player->y][player->x] = VOID;
		printf("1");
	}
	else
	{
		if (data->is_on_exit)
		{
			data->is_on_exit = 0;
			map[player->y][player->x] = EXIT;
			printf("2");
		}
		else
		{
			map[player->y][player->x] = VOID;
			printf("3");
		}
		printf("4");
	}
	printf("5");
	map[player->y + 1][player->x] = PLAYER;
	return (1);
}
int	ft_move(int keycode, t_ptr	*data)
{
	if (keycode == UP)
		ft_go_up(data);
	else if (keycode == DOWN)
		ft_go_down(data);
	ft_show_array2D(data->map);
	ft_putstr_fd("\n", 1);
	return (1);
}