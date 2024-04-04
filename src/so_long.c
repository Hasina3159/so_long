#include "so_long.h"

int main(int argc, char **argv)
{
	t_ptr	data;
	char	*path;
	char	**array2D;
	t_imgs	*img;

	if (argc == 2)
	{
		path = argv[1];
		ft_check_all(path);
		data.is_on_exit = 0;
		printf("Line number : [%d]\n", ft_get_line_number(path));
		array2D = ft_file_to_array2D(path);
		ft_show_array2D(array2D);
		data.map = array2D;
		data.path = path;
		data.mlx = mlx_init();
		if (!data.mlx)
			ft_error("Erreur lors de l'initialisation de MiniLibX\n", EXIT_FAILURE);
		data.win = mlx_new_window(data.mlx, ft_get_map_x(data.map) * SIZE, (ft_get_map_y(data.map) + 1) * SIZE, "so_long");
		img = ft_path_to_img("sprite/player/P1.xpm", &data);
		img->coord.x = 0;
		img->coord.y = SIZE;
		(void) img;
		printf("IMG : [%p]\n", img->img);
		//mlx_put_image_to_window(data.mlx, data.win, img->img, 0, 0);
		/*sleep(1);
		mlx_destroy_image(data.mlx, img->img);*/
		ft_draw_map(&data);
		ft_draw_wall(&data);
		ft_show_img(img, &data);
		//ft_show_img(img, &data);
		ft_putstr_fd("6", 1);
		if (!data.win)
			ft_putstr_fd("Erreur lors de la création de la fenêtre\n", EXIT_FAILURE);
		ft_get_player_coord(&data);
		printf("X : %d, Y : %d\n", data.player.x, data.player.y);
		ft_close_event(&data);
		mlx_loop(data.mlx);
	}
	
	return 0;
}