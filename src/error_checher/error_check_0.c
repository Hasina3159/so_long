#include "../so_long.h"

void	ft_error(char *err_msg, int	exit_status)
{
	ft_putstr_fd(err_msg, 2);
	exit (exit_status);
}

int	ft_check_file_validity(char *path)
{
	int	fd;

	if (path == NULL)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	ft_is_valid_char(char c)
{
	if (c == PLAYER || c == WALL || c == EXIT || c == ITEM || c == VOID)
		return (1);
	if (c == MONSTER)
		return (1);
	return (0);
}

int	ft_check_content_valididy(int fd)
{
	char	*line;
	int		i;
	size_t	len;

	line = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return  (-1);
	len = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != len && ft_strchr(line, '\n'))
			return (free(line), -2);
		if (ft_strlen(line) != len - 1 && !ft_strchr(line, '\n'))
			return (free(line), -2);
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			if (!ft_is_valid_char(line[i++]))
				return  (free(line), -1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_check_extension(char *path)
{
	size_t	l;

	if (path == NULL || ft_strlen(path) <= 4)
		return (0);
	l = ft_strlen(path);
	if (path[l - 4] != '.' || path[l - 3] != 'b')
		return (0);
	if (path[l - 2] != 'e' || path[l - 1] != 'r')
		return (0);
	return (1);
}
