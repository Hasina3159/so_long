#include "so_long.h"

int ft_close_window(t_ptr *data)
{
	int	i;

	mlx_destroy_display(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	if (data->map)
		free(data->map);
	if (data->mlx)
		free(data->mlx);
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