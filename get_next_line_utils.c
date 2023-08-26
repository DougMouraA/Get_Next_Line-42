/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:59:32 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/08/15 11:03:21 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	c = c % 256;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *) str);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	size;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = 0;
	}
	if (!s2)
	{
		free (s1);
		return (0);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = (char *)malloc(size);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(newstr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free (s1);
	return (newstr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	d;
	size_t	i;
	char	*str;

	str = (char *)s;
	d = c;
	i = 0;
	while (i < n)
	{
		str[i] = d;
		i++;
	}
	return (str);
}
