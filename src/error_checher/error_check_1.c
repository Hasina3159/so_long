#include "../so_long.h"

int	ft_check_all(char *path)
{
	int	fd;
	int	err;

	fd = ft_check_file_validity(path);
	if (fd == -1)
		ft_error("File opening error!\n", EXIT_FAILURE);
	if (ft_check_extension(path) == 0)
		ft_error("File extension error!\n", EXIT_FAILURE);
	err = ft_check_content_valididy(fd);
	if ( err == -1)
		ft_error("File content error!\n", EXIT_FAILURE);
	else if ( err == -2)
		ft_error("Non-rectangular map!\n", EXIT_FAILURE);
	close(fd);
	return (1);
}
int	ft_count_element(char **map, char element)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_check_count(char **map)
{
	if (ft_count_element(map, PLAYER) != 1 || ft_count_element(map, EXIT) != 1)
		return (0);
	if (ft_count_element(map, ITEM) <= 0)
		return (0);
	return (1);
}