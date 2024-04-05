#include "../so_long.h"

unsigned int	ft_coord_to_px(t_imgs *img, int x, int y)
{
	unsigned int    px;

	px = *(img->addr + ((y * img->size_line) + (x * (img->bpp / 8))));
	printf("COLOR : [%x]\n", px);
	return (px);
}

void	ft_pixel_transparent(t_imgs *img, int x, int y, unsigned int color)
{
	char	*data;

	if (color == 0x00000000)
		return ;
	data = img->addr + ((y * img->size_line) + (x * (img->bpp / 8)));
	*(unsigned int *) data = color;
}

void    ft_layer_add(t_imgs *src, t_imgs *dst)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			ft_pixel_transparent(dst, x, y, ft_coord_to_px(src, x, y));
			x++;
		}
		y++;
	}
}

void	ft_blended_imgs(t_imgs *back, t_imgs *front, t_ptr *data, t_coord coord)
{
	t_imgs	new;

	new.img = mlx_new_image(data->mlx, SIZE, SIZE);
	ft_putstr_fd("1\n", 1);
	new.addr = mlx_get_data_addr(new.img, &new.bpp, &new.size_line, &new.endian);
	ft_putstr_fd("2\n", 1);
	back->addr = mlx_get_data_addr(back->img, &back->bpp, &back->size_line, &back->endian);
	ft_layer_add(back, &new);
	ft_putstr_fd("3\n", 1);
	front->addr = mlx_get_data_addr(front->img, &front->bpp, &front->size_line, &front->endian);
	ft_layer_add(front, &new);
	ft_putstr_fd("4\n", 1);
	ft_putstr_fd("5\n", 1);
	new.coord.x = coord.x;
	new.coord.y = coord.y;
	ft_show_img(&new, data);
	ft_putstr_fd("6\n", 1);
}