#include "../so_long.h"

void    ft_init_animation(t_animation *animation, t_ptr *data, char *paths)
{
	char	**splited_paths;
	int		size;
	int		i;

	splited_paths = ft_split(paths, ' ');
	if (splited_paths == NULL)
		return ;
	size = ft_get_map_y(splited_paths);
	animation->imgs = (t_imgs **)malloc(sizeof(t_imgs*) * (size + 1));
	if (animation->imgs == NULL)
		return ;
	animation->imgs[size] = NULL;
	i = 0;
	while (i < size)
	{
		ft_path_to_img(splited_paths[i], data, 0, 0);
		i++;
	}
	animation->delay = 1000;
	animation->ending = 1000;
	free(splited_paths);
}
void	ft_animate(t_animation *animation, t_ptr *data)
{
	int	i;

	(void) data;
	while (1)
	{
		i = 0;
		usleep(1000);
		while (animation->imgs[i])
		{
			usleep(animation->delay);
			i++;
		}
	}
	
}