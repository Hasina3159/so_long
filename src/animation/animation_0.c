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

void    ft_anim(t_animation *anim, t_ptr *data)
{
	anim->delay = 100000;
	anim->ending = 100000;
	ft_animate_player(anim, data);
}
int	ft_animation(void *data)
{
	t_animation	anim;
	t_ptr		*data_ptr;

	data_ptr = (t_ptr *)data;
	anim.coord = data_ptr->player;
	ft_anim(&anim, data_ptr);
	return (0);
}