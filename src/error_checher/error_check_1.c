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
