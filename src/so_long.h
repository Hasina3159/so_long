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
# define MONSTER 'M'

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
	char	**map_tmp;
	t_coord	player;
	int		is_on_exit;
	char	*path;
	char	**p_anim;
	char	**e_anim;
}			t_ptr;

typedef struct s_imgs
{
	void			*img;
	char			*addr;
	int				img_width;
	int				img_height;
	int				bpp;
	int				size_line;
	int				endian;
	char			type;
	t_coord			coord;
}					t_imgs;

typedef struct s_animation
{
	char	**paths;
	int		delay;
	int		ending;
	t_coord	coord;
}			t_animation;

int		ft_check_file_validity(char *path);
int		ft_check_content_valididy(int fd);
int		ft_check_extension(char *path);
int		ft_check_all(char *path);
char    **ft_array2D_dup(char **map);
int		ft_check_player(t_ptr *data, int x, int y);
void	ft_check_player_path(t_ptr *data, int x, int y, int *is_valid);
int		ft_count_element(char **map, char element);
int		ft_check_count(char **map);

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

void	ft_path_to_img(char *path, t_ptr *data, int x, int y);
void    ft_free_img(t_imgs *img, t_ptr *data);

void    ft_coord_to_map(t_ptr *data, t_imgs **img, int x, int y);
void    ft_draw_map(t_ptr *data);
void    ft_clear_map(t_ptr *data);
void    ft_update_map(t_ptr *data);
void    ft_draw_map_tmp(t_ptr *data);

int 	ft_wall_has_u(char **map, int x, int y);
int 	ft_wall_has_d(char **map, int x, int y);
int 	ft_wall_has_l(char **map, int x, int y);
int 	ft_wall_has_r(char **map, int x, int y);
int 	ft_wall_has_ud(char **map, int x, int y);
int 	ft_wall_has_lr(char **map, int x, int y);
int 	ft_wall_ud(char **map, int x, int y);
int 	ft_wall_lr(char **map, int x, int y);
void    ft_draw_wall(t_ptr *data);

void	ft_blended_imgs(t_imgs *back, t_imgs *front, t_ptr *data, t_coord coord);

int		ft_animation(void *data);
char    **ft_array2D_dup(char **map);
void	ft_anim_coord(char **map, char element, t_coord *dst);
void	ft_animate_enemy(t_animation *anim, t_ptr *data);

void	ft_free_2D(char **array2D);

#endif