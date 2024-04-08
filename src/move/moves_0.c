#include "../so_long.h"

static void	ft_condition(t_ptr *data, int *move, char element)
{
	if (element == 'u')
	{
		ft_collide(data, MONSTER, 'u', "GAME OVER!\n");
		ft_exit_collide(data, 'u');
		*move = *move + ft_go_up(data, move);
	}
	else if (element == 'd')
	{
		ft_collide(data, MONSTER, 'd', "GAME OVER!\n");
		ft_exit_collide(data, 'd');
		*move = *move + ft_go_down(data, move);
	}
	else if (element == 'l')
	{
		ft_collide(data, MONSTER, 'l', "GAME OVER!\n");
		ft_exit_collide(data, 'l');
		*move = *move + ft_go_left(data, move);
	}
	else if (element == 'r')
	{
		ft_collide(data, MONSTER, 'r', "GAME OVER!\n");
		ft_exit_collide(data, 'r');
		*move = *move + ft_go_right(data, move);
	}
}

int	ft_move(int keycode, t_ptr	*data)
{
	char		*text;
	int			move;

	move = 0;
	ft_clear_map(data);
	if (keycode == UP)
		ft_condition(data, &move, 'u');
	else if (keycode == DOWN)
		ft_condition(data, &move, 'd');
	else if (keycode == LEFT)
		ft_condition(data, &move, 'l');
	else if (keycode == RIGHT)
		ft_condition(data, &move, 'r');
	text = ft_itoa(move);
	ft_path_to_img("./sprite/others/V.xpm", data, 0, -1);
	ft_path_to_img("./sprite/others/V.xpm", data, 1, -1);
	mlx_string_put(data->mlx, data->win, 20, 20, INT_MAX, "MOVE : ");
	mlx_string_put(data->mlx, data->win, 60, 20, INT_MAX, text);
	free(text);
	if (move)
	{
		ft_update_map(data);
		mlx_loop_hook(data->mlx, ft_animation, data);
	}
	return (1);
}
