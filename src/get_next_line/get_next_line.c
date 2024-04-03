/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:32:25 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/04/03 11:06:45 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_null_char(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}

static void	ft_init(int fd, t_file *file)
{
	int	i;

	file->fd = fd;
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		file->buffer[i] = 0;
		i++;
	}
	return ;
}

static int	ft_condition(t_file *file, int *x, char **final)
{
	*x = read(file->fd, file->buffer, BUFFER_SIZE);
	if (*x > 0)
	{
		ft_null_char(&file->buffer[*x]);
		*final = ft_strjoin_gnl(*final, file->buffer);
		return (1);
	}
	return (0);
}

static char	*ft_read_line(t_file *file, char *tmp1, int x)
{
	char	*final;

	final = ft_strdup(file->buffer);
	if (BUFFER_SIZE == 0 || file->fd < 0)
		return (free(final), NULL);
	while (!ft_strchr(final, '\n') && ft_condition(file, &x, &final))
		continue ;
	if (final == NULL)
		return (NULL);
	if (!*final)
		return (free(final), NULL);
	tmp1 = ft_strchr(file->buffer, '\n');
	if (tmp1)
	{
		ft_null_char(ft_strchr(final, '\n') + 1);
		ft_strcpy(file->buffer, &tmp1[1]);
	}
	else
		ft_null_char(file->buffer);
	return (final);
}

char	*get_next_line(int fd)
{
	static t_file	file;
	int				x;
	char			*tmp1;
	char			*final;

	tmp1 = NULL;
	x = 0;
	if (file.fd != fd)
		ft_init(fd, &file);
	final = ft_read_line(&file, tmp1, x);
	free(tmp1);
	return (final);
}
