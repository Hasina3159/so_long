#include "../so_long.h"

void    ft_draw(t_ptr *data, char element, char *path)
{
	int     i;
	int     j;

	i = 0;
	while (i < ft_get_map_y(data->map))
	{
		j = 0;
		while (j < ft_get_map_x(data->map))
		{
			if (data->map[i][j] == element)
				ft_path_to_img(path, data, j, i);
			j++;
		}
		i++;
	}
}

void    ft_draw_tmp(t_ptr *data, char element, char *path)
{
	int     i;
	int     j;

	i = 0;
	while (i < ft_get_map_y(data->map_tmp))
	{
		j = 0;
		while (j < ft_get_map_x(data->map_tmp))
		{
			if (data->map_tmp[i][j] == element)
				ft_path_to_img(path, data, j, i);
			j++;
		}
		i++;
	}
}

void    ft_draw_map(t_ptr *data)
{
	ft_draw(data, WALL, "./sprite/wall/O.xpm");
	ft_draw(data, PLAYER, "./sprite/player/P1.xpm");
	ft_draw(data, ITEM, "./sprite/others/C.xpm");
	ft_draw(data, EXIT, "./sprite/others/E.xpm");
}
void    ft_draw_map_tmp(t_ptr *data)
{
	ft_draw_tmp(data, '.', "./sprite/wall/O.xpm");
	ft_draw_tmp(data, PLAYER, "./sprite/player/P1.xpm");
	ft_draw_tmp(data, ITEM, "./sprite/others/C.xpm");
	ft_draw_tmp(data, EXIT, "./sprite/others/E.xpm");
}

void    ft_clear_map(t_ptr *data)
{
	ft_draw(data, PLAYER, "./sprite/others/V.xpm");
	ft_draw(data, EXIT, "./sprite/others/E.xpm");
}

void    ft_update_map(t_ptr *data)
{
	ft_draw(data, PLAYER, "./sprite/player/P1.xpm");
}
