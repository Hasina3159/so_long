#include "../so_long.h"

t_imgs   *ft_path_to_img(char *path, t_ptr *data)
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
		ft_putstr_fd(path, 1);
		ft_error("Img not found!", EXIT_FAILURE);
	}
	img->coord.x = 0;
	img->coord.y = 0;
	return (img);
}

void    ft_show_img(t_imgs *img, t_ptr *data)
{
	mlx_put_image_to_window(data->mlx, data->win, img->img, img->coord.x, img->coord.y);
}
void    ft_free_img(t_imgs *img, t_ptr *data)
{
	if (!img)
		return ;
	if (img->img)
	{
		mlx_destroy_image(data->mlx, img->img);
		if (img->img)
			free(img->img);
	}
	free(img);
}