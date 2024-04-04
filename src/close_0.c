#include "so_long.h"

int ft_close_window(t_ptr *data)
{
	(void) data;
	exit (0);
}

int	ft_close_key_hook(int keycode, t_ptr *data)
{
	if (keycode == ESC)
		ft_close_window(data);
	return (0);
}

void    ft_close_event(t_ptr *data)
{
	mlx_key_hook(data->win, ft_close_key_hook, data);
	mlx_hook(data->win, 2, 1L<<0, ft_move, data);
	mlx_hook(data->win, 17, 0, ft_close_window, data);
	mlx_hook(data->win, 17, 0, ft_close_window, data);
}