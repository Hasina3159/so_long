#include "so_long.h"

void	ft_anim_coord(char **map, char element, t_coord *dst)
{
	int		i;
	int		j;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
			{
				dst->x = j;
				dst->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}