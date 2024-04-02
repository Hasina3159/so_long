#include "so_long.h"

int close_window(t_ptr *param) {
    (void) param;
    exit (0);
}

int main() {
    t_ptr data;

    data.mlx = mlx_init();
    if (!data.mlx) {
        ft_putstr_fd("Erreur lors de l'initialisation de MiniLibX\n", 2);
        exit (EXIT_FAILURE);
    }
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Ma fenetre");
    if (!data.win) {
        ft_putstr_fd("Erreur lors de la création de la fenêtre\n", 2);
        exit (EXIT_FAILURE);
    }
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
    return 0;
}