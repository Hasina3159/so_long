#include "../so_long.h"

int ft_go_up(t_ptr *data, int *move)
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
		return (0);
	else if (up == EXIT)
	{
		data->is_on_exit = 1;
		map[player->y][player->x] = VOID;
	}
	else
	{
		if (ft_data_exit(data, map, player))
			(void) up;
		else
			map[player->y][player->x] = VOID;
	}
	map[player->y - 1][player->x] = PLAYER;
	*move = *move + 1;
	return (1);
}

int ft_go_down(t_ptr *data, int *move)
{
	t_coord	*player;
	char	**map;
	char	down;

	ft_get_player_coord(data);
	player = &data->player;
	map = data->map;
	if (player->y >= ft_get_map_y(map) - 1)
		return (0);
	down = ft_get_data_from_coord(data, player->x, player->y + 1);
	if (down == WALL)
		return (0);
	else if (down == EXIT)
	{
		data->is_on_exit = 1;
		map[player->y][player->x] = VOID;
	}
	else
	{
		if (ft_data_exit(data, map, player))
			(void) down;
		else
			map[player->y][player->x] = VOID;
	}
	map[player->y + 1][player->x] = PLAYER;
	*move = *move + 1;
	return (1);
}
int ft_go_left(t_ptr *data, int *move)
{
	t_coord	*player;
	char	**map;
	char	left;

	ft_get_player_coord(data);
	player = &data->player;
	map = data->map;
	if (player->x <= 0)
		return (0);
	left = ft_get_data_from_coord(data, player->x - 1, player->y);
	if (left == WALL)
		return (0);
	else if (left == EXIT)
	{
		data->is_on_exit = 1;
		map[player->y][player->x] = VOID;
	}
	else
	{
		if (ft_data_exit(data, map, player))
			(void) left;
		else
			map[player->y][player->x] = VOID;
	}
	map[player->y][player->x - 1] = PLAYER;
	*move = *move + 1;
	return (1);
}
int ft_go_right(t_ptr *data, int *move)
{
	t_coord	*player;
	char	**map;
	char	right;

	ft_get_player_coord(data);
	player = &data->player;
	map = data->map;
	if (player->x >= ft_get_map_x(map) - 1)
		return (0);
	right = ft_get_data_from_coord(data, player->x + 1, player->y);
	if (right == WALL)
		return (0);
	else if (right == EXIT)
	{
		data->is_on_exit = 1;
		map[player->y][player->x] = VOID;
	}
	else
	{
		if (ft_data_exit(data, map, player))
			(void) right;
		else
			map[player->y][player->x] = VOID;
	}
	map[player->y][player->x + 1] = PLAYER;
	*move = *move + 1;
	return (1);
}

void ft_exit_collide(t_ptr *data, char direction)
{
	if (!ft_count_element(data->map, ITEM))
		ft_collide(data, EXIT, direction, "YOU WIN!\n");
}
