#include "so_long.h"

int main(int argc, char **argv)
{
	t_ptr	data;
	char	*path;
	char	**array2D;

	if (argc == 2)
	{
		path = argv[1];
		ft_check_all(path);
		data.is_on_exit = 0;
		printf("Line number : [%d]\n", ft_get_line_number(path));
		array2D = ft_file_to_array2D(path);
		ft_show_array2D(array2D);
		data.map = array2D;
		data.mlx = mlx_init();
		if (!data.mlx)
			ft_error("Erreur lors de l'initialisation de MiniLibX\n", EXIT_FAILURE);
		data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
		if (!data.win)
			ft_putstr_fd("Erreur lors de la création de la fenêtre\n", EXIT_FAILURE);
		ft_get_player_coord(&data);
		printf("X : %d, Y : %d\n", data.player.x, data.player.y);
		ft_close_event(&data);
		mlx_loop(data.mlx);
	}
	
	return 0;
}