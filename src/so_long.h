#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
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

# define SIZE 64

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
	char	*path;
}			t_ptr;

typedef struct s_imgs
{
	void			*img;
	int				img_width;
	int				img_height;
	char			type;
	t_coord			coord;
}					t_imgs;

typedef struct s_animation
{
	t_imgs	**imgs;
	int		delay;
	int		ending;
	t_coord	coord;
}			t_animation;

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
int		ft_get_player_coord(t_ptr *data);
int		ft_data_exit(t_ptr *data, char **map, t_coord *player);
char	ft_get_data_from_coord(t_ptr *data, int x, int y);
int		ft_get_map_y(char **map);
int		ft_get_map_x(char **map);

t_imgs   *ft_path_to_img(char *path, t_ptr *data);
void    ft_show_img(t_imgs *img, t_ptr *data);
void    ft_free_img(t_imgs *img, t_ptr *data);

void    ft_coord_to_map(t_ptr *data, t_imgs **img, int x, int y);
void    ft_draw_map(t_ptr *data);

#endif