#include "../so_long.h"

void    ft_coord_to_wall(t_ptr *data, t_imgs **img, int x, int y)
{
	*img = *img;
	if(!(ft_wall_has_l(data->map, x, y) || ft_wall_has_r(data->map, x, y)))
	{
		if (ft_wall_has_ud(data->map, x, y))
			*img = ft_path_to_img("sprite/wall/V2.xpm", data);
		else if (ft_wall_has_u(data->map, x, y))
			*img = ft_path_to_img("sprite/wall/V3.xpm", data);
		else if (ft_wall_has_d(data->map, x, y))
			*img = ft_path_to_img("sprite/wall/V1.xpm", data);
	}
	else
	{
		if (ft_wall_has_lr(data->map, x, y))
			*img = ft_path_to_img("sprite/wall/H2.xpm", data);
		else if (ft_wall_has_l(data->map, x, y))
			*img = ft_path_to_img("sprite/wall/H3.xpm", data);
		else if (ft_wall_has_r(data->map, x, y))
			*img = ft_path_to_img("sprite/wall/H1.xpm", data);
	}
	if(!ft_wall_lr(data->map, x, y) && !ft_wall_ud(data->map, x, y))
		*img = ft_path_to_img("sprite/wall/O.xpm", data);
}

void    ft_draw_wall(t_ptr *data)
{
	int     i;
	int     j;
	t_imgs  *img;

	i = 1;
	while (i < ft_get_map_y(data->map) - 1)
	{
		j = 1;
		while (j < ft_get_map_x(data->map) - 1)
		{
			img = NULL;
			if (data->map[i][j] == WALL)
			{
				if (img)
				{
					ft_coord_to_wall(data, &img, j, i);
					img->coord.x = j * SIZE;
					img->coord.y = (i + 1) * SIZE; 
				}
			}
			j++;
		}
		i++;
	}
}