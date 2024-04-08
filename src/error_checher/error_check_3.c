#include "../so_long.h"

void		ft_check_player_path(t_ptr *data, int x, int y, int *is_valid)
{
	int	valid;
	if (data->map_tmp[y][x] == EXIT)
	{
		*is_valid = 1;
		return ;
	}
	if (*is_valid)
		return ;
	data->map_tmp[y][x] = WALL;
	valid = 0;
	if (data->map_tmp[y][x + 1] != '.' && data->map_tmp[y][x + 1] != WALL)
	{
		ft_check_player_path(data, x + 1, y, is_valid);
		valid++;
	}
	if (data->map_tmp[y - 1][x] != '.' && data->map_tmp[y - 1][x] != WALL)
	{
		ft_check_player_path(data, x, y - 1, is_valid);
		valid++;
	}
	if (data->map_tmp[y][x - 1] != '.' && data->map_tmp[y][x - 1] != WALL)
	{
		ft_check_player_path(data, x - 1, y, is_valid);
		valid++;
	}
	if (data->map_tmp[y + 1][x] != '.' && data->map_tmp[y + 1][x] != WALL)
	{
		ft_check_player_path(data, x, y + 1, is_valid);
		valid++;
	}
	if (valid == 0)
		data->map_tmp[y][x] = VOID;
}

int	ft_check_player(t_ptr *data, int x, int y)
{
	int		is_valid;
	int		i;

	(void) x;
	(void) y;
	is_valid = 0;
	ft_check_player_path(data, x, y, &is_valid);
		i = 0;
	while (data->map_tmp[i])
	{
		free(data->map_tmp[i]);
		i++;
	}
	free(data->map_tmp);
	return (is_valid);
}

int	ft_collide(t_ptr *data, char element, char move, char *message)
{
	int		x;
	int		y;
	t_coord	coord;
	char	**map;

	x = 0;
	y = 0;
	if (move == 'u')
		y--;
	else if (move == 'd')
		y++;
	if (move == 'l')
		x--;
	else if (move == 'r')
		x++;
	map = data->map;
	coord = data->player;
	if (map[coord.y + y][coord.x + x] == element)
	{
		ft_putstr_fd(message, 1);
		ft_close_window(data);
	}
	return (0);
}
