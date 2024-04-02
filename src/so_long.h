#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"

# define VOID '0'
# define WALL '1'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define UP
# define DOWN
# define LEFT
# define RIGHT

# define WIN_WIDTH 64*80
# define WIN_HEIGHT 64*60

typedef struct s_ptr {
	void	*mlx;
	void	*win;
}			t_ptr;

#endif