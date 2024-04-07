#include "../so_long.h"

void    ft_coord_to_wall(t_ptr *data, int x, int y)
{
	if(!(ft_wall_has_l(data->map, x, y) || ft_wall_has_r(data->map, x, y)))
	{
		if (ft_wall_has_ud(data->map, x, y))
			ft_path_to_img("sprite/wall/V2.xpm", data, x, y);
		else if (ft_wall_has_u(data->map, x, y))
			ft_path_to_img("sprite/wall/V3.xpm", data, x, y);
		else if (ft_wall_has_d(data->map, x, y))
			ft_path_to_img("sprite/wall/V1.xpm", data, x, y);
	}
	else
	{
		if (ft_wall_has_lr(data->map, x, y))
			ft_path_to_img("sprite/wall/H2.xpm", data, x, y);
		else if (ft_wall_has_l(data->map, x, y))
			ft_path_to_img("sprite/wall/H3.xpm", data, x, y);
		else if (ft_wall_has_r(data->map, x, y))
			ft_path_to_img("sprite/wall/H1.xpm", data, x, y);
	}
	if(!ft_wall_lr(data->map, x, y) && !ft_wall_ud(data->map, x, y))
		ft_path_to_img("sprite/wall/O.xpm", data, x, y);
}

void    ft_draw_wall(t_ptr *data)
{
	int     i;
	int     j;

	i = 1;
	while (i < ft_get_map_y(data->map) - 1)
	{
		j = 1;
		while (j < ft_get_map_x(data->map) - 1)
		{
			if (data->map[i][j] == WALL)
				ft_coord_to_wall(data, j, i);
			j++;
		}
		i++;
	}
}