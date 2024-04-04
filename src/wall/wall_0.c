#include "../so_long.h"

void    ft_coord_to_map(t_ptr *data, t_imgs **img, int x, int y)
{
	*img = *img;
	if(y == 0)
	{
		if (x == 0)
		{
			*img = ft_path_to_img("sprite/map/M1.xpm", data);
			ft_putstr_fd("ATO", 1);
		}
		else if (x == ft_get_map_x(data->map) - 1)
			*img = ft_path_to_img("sprite/map/M3.xpm", data);
		else
			*img = ft_path_to_img("sprite/map/M2.xpm", data);
	}
	else if (y == ft_get_map_y(data->map) - 1)
	{
		if (x == 0)
			*img = ft_path_to_img("sprite/map/M7.xpm", data);
		else if (x == ft_get_map_x(data->map) - 1)
			*img = ft_path_to_img("sprite/map/M9.xpm", data);
		else
			*img = ft_path_to_img("sprite/map/M8.xpm", data);
	}
	else
	{
		if (x == 0)
			*img = ft_path_to_img("sprite/map/M4.xpm", data);
		else if (x == ft_get_map_x(data->map) - 1)
			*img = ft_path_to_img("sprite/map/M6.xpm", data);
		else
			*img = ft_path_to_img("sprite/map/M5.xpm", data);
	}
}

void    ft_draw_wall(t_ptr *data)
{
	int     i;
	int     j;
	t_imgs  *img;

	i = 0;
	j = 0;
	while (i < ft_get_map_y(data->map))
	{
		j = 0;
		while (j < ft_get_map_x(data->map))
		{
			img = NULL;
			ft_coord_to_map(data, &img, j, i);
			img->coord.x = j * SIZE;
			img->coord.y = (i + 1) * SIZE; 
			ft_show_img(img, data);
			j++;
		}
		i++;
	}
}