#include "so_long.h"

char    **ft_array2D_dup(char **map)
{
	int		i;
	int		len;
	char	**final;

	if (!map)
		ft_error("Void map!\n", EXIT_FAILURE);
	len = ft_get_map_y(map);
	printf("\nLen : [%d]\n", len);
	final = (char **)malloc(sizeof(char) * (len + 1));
	if (!final)
		ft_error("Dup allocation error!\n", EXIT_FAILURE);
	final[len] = NULL;
	i = 0;
	while (map[i])
	{
		final[i] = ft_strdup(map[i]);
		if (final[i] == NULL)
			ft_error("Dup allocation error!\n", EXIT_FAILURE);
		i++;
	}
	return (final);
}
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

void	ft_free_2D(char **array2D)
{
	int	y;

	if (array2D == NULL)
		return ;
	y = 0;
	while (array2D[y])
	{
		if (array2D[y])
			free(array2D[y]);
		y++;
	}
	if (array2D)
		free(array2D);
}