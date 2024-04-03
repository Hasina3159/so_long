/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:32:22 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/04/03 11:07:00 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_file
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
}			t_file;

void	ft_null_char(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*get_next_line(int fd);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *s);
void	ft_strcpy(char *dst, const char *src);

#endif