/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:32:16 by ntodisoa          #+#    #+#             */
/*   Updated: 2024/04/03 11:06:12 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*final;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	final = (char *)malloc(sizeof(char) * (len + 1));
	if (final == NULL)
		return (NULL);
	final[len] = 0;
	i = 0;
	j = 0;
	while (s1[i])
		final[j++] = s1[i++];
	i = 0;
	while (s2[i])
		final[j++] = s2[i++];
	free(s1);
	return (final);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strdup(const char *s)
{
	char	*final;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s) + 1;
	final = (char *)malloc(sizeof(char) * (len));
	if (final == NULL)
		return (NULL);
	final[len - 1] = 0;
	i = 0;
	while (s[i])
	{
		final[i] = s[i];
		i++;
	}
	return (final);
}
