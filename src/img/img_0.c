#include "../so_long.h"

void    ft_show_img(t_imgs *img, t_ptr *data)
{
	mlx_put_image_to_window(data->mlx, data->win, img->img, img->coord.x, img->coord.y);
	ft_free_img(img, data);
}

void	ft_path_to_img(char *path, t_ptr *data, int x, int y)
{
	t_imgs   *img;

	if (path == NULL)
		ft_error("Image path error!\n", EXIT_FAILURE);
	img = (t_imgs *)malloc(sizeof(t_imgs));
	if (img == NULL)
		ft_error("Image allocation error!\n", EXIT_FAILURE);
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width, &img->img_height);
	if (img->img == NULL)
	{
		ft_putstr_fd(path, 2);
		ft_error(" : Img not found!", EXIT_FAILURE);
	}
	img->coord.x = x * SIZE;
	img->coord.y = (y + 1) * SIZE;
	ft_show_img(img, data);
}

void    ft_free_img(t_imgs *img, t_ptr *data)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(data->mlx, img->img);
	free(img);
}