#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define VOID '0'
# define WALL '1'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307

# define WIN_WIDTH 64*20
# define WIN_HEIGHT 64*16

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	char	**map;
	t_coord	player;
	int		is_on_exit;
}			t_ptr;



int		ft_check_file_validity(char *path);
int		ft_check_content_valididy(int fd);
int		ft_check_extension(char *path);
int		ft_check_all(char *path);

int		ft_close_window(t_ptr *data);
void	ft_error(char *err_msg, int	exit_status);
void	ft_close_event(t_ptr *data);

int		ft_get_line_number(char *path);
char	**ft_file_to_array2D(char *path);
void	ft_show_array2D(char **array2D);

int 	ft_get_player_coord(t_ptr *data);

int		ft_move(int keycode, t_ptr	*data);


#endif