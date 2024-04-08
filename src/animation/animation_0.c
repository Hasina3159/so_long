#include "../so_long.h"

void	ft_animate_player(t_animation *anim, t_ptr *data)
{
	static int	i = 0;
	t_ptr		tmp;
	

	ft_anim_coord(data->map, PLAYER, &tmp.player);
	if (tmp.player.y != data->player.y || tmp.player.x != data->player.x)
	{
		ft_get_player_coord(data);
		ft_clear_map(data);
		return ;
	}
	if (!data->p_anim[i])
		i = 0;
	usleep(anim->delay);
	ft_path_to_img(data->p_anim[i], data, anim->coord.x, anim->coord.y);
	i++;
}

void	ft_animate_enemy(t_animation *anim, t_ptr *data)
{
	static int	i = 0;
	t_ptr		tmp;
	

	ft_anim_coord(data->map, PLAYER, &tmp.player);
	if (tmp.player.y != data->player.y || tmp.player.x != data->player.x)
	{
		ft_get_player_coord(data);
		ft_clear_map(data);
		return ;
	}
	if (!data->e_anim[i])
		i = 0;
	usleep(anim->delay);
	ft_path_to_img(data->e_anim[i], data, anim->coord.x, anim->coord.y);
	i++;
}

void	ft_get_enemy_coord(t_animation *anim_e, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == MONSTER)
			{
				anim_e->coord.x = x;
				anim_e->coord.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void    ft_anim(t_animation *anim_p, t_animation *anim_e, t_ptr *data)
{
	anim_p->delay = 30000;
	anim_p->ending = 500000;
	anim_e->delay = 30000;
	anim_e->ending = 500000;
	ft_animate_player(anim_p, data);
	ft_animate_enemy(anim_e, data);
}
int	ft_animation(void *data)
{
	t_animation	anim_p;
	t_animation	anim_e;
	t_ptr		*data_ptr;

	data_ptr = (t_ptr *)data;
	anim_p.coord = data_ptr->player;
	ft_get_enemy_coord(&anim_e, data_ptr->map);
	ft_anim(&anim_p, &anim_e, data_ptr);
	return (0);
}