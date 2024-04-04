#include "../so_long.h"

int	ft_get_line_number(char *path)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error while opening file!\n", EXIT_FAILURE);
	tmp = NULL;
	tmp = get_next_line(fd);
	i = 0;
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
	return (i);
}

char	**ft_file_to_array2D(char *path)
{
	int		fd;
	char	**final;
	int		len;
	int		i;

	fd = open(path, O_RDONLY);
	len = ft_get_line_number(path);
	final = (char **)malloc(sizeof(char *) * (len + 1));
	if (fd == -1 || final == NULL)
		ft_error("Error while parsing file!\n", EXIT_FAILURE);
	final[len] = NULL;
	i = 0;
	while(i < len)
	{
		final[i] = get_next_line(fd);
		if (final[i][ft_strlen(final[i]) - 1] == '\n')
			final[i][ft_strlen(final[i]) - 1] = 0;
		i++;
	}
	return (final);	
}
void show(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_show_array2D(char **array2D)
{
	int	i;
	int	j;

	i = 0;
	while (array2D[i])
	{
		j = 0;
		while (array2D[i][j])
		{
			if (array2D[i][j] == PLAYER)
				show("☃");
			else if (array2D[i][j] == WALL)
				show("▆");
			else if (array2D[i][j] == ITEM)
				show("○");
			else if (array2D[i][j] == VOID)
				show(" ");
			else if (array2D[i][j] == EXIT)
				show("⤪");
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}