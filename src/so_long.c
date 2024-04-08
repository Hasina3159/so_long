#include "so_long.h"

int main(int argc, char **argv)
{
	t_ptr	data;
	char	*path;

	if (argc == 2)
	{
		path = argv[1];
		ft_check_all(path);
		data.is_on_exit = 0;
		data.map = ft_file_to_array2D(path);
		data.map_tmp = ft_file_to_array2D(path);
		data.path = path;
		data.mlx = mlx_init();
		if (!data.mlx)
			ft_error("Erreur lors de l'initialisation de MiniLibX\n", EXIT_FAILURE);
		data.win = mlx_new_window(data.mlx, ft_get_map_x(data.map) * SIZE, (ft_get_map_y(data.map) + 1) * SIZE, "so_long");
		ft_draw_map(&data);
		if (!data.win)
			ft_putstr_fd("Erreur lors de la création de la fenêtre\n", EXIT_FAILURE);
		ft_get_player_coord(&data);
		if (!ft_check_player(&data, data.player.x, data.player.y))
			ft_error("No path!\n", EXIT_FAILURE);
		data.p_anim = ft_split("./sprite/player/P1.xpm ./sprite/player/P2.xpm ./sprite/player/P3.xpm ./sprite/player/P4.xpm ./sprite/player/P5.xpm ./sprite/player/P6.xpm", ' ');
		data.e_anim = ft_split("./sprite/enemy/P1.xpm ./sprite/enemy/P2.xpm ./sprite/enemy/P3.xpm ./sprite/enemy/P4.xpm ./sprite/enemy/P5.xpm ./sprite/enemy/P6.xpm ./sprite/enemy/P7.xpm", ' ');
		ft_close_event(&data);
		mlx_loop(data.mlx);
	}
	
	return 0;
}
