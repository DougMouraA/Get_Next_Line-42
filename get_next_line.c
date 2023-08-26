/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:11:52 by douglasmour       #+#    #+#             */
/*   Updated: 2022/08/17 11:36:39 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest(char *buffer)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	size = ft_strlen(buffer) - i;
	if (size < 1)
	{
		free (buffer);
		return (0);
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, &buffer[i], size + 1);
	free (buffer);
	return (str);
}

char	*pickline(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	ft_strlcpy (str, buffer, i + 1);
	return (str);
}

char	*read_buf(int fd, char *buffer)
{
	char	*str_aux;
	int		nbytes;

	nbytes = 1;
	str_aux = (char *)malloc(BUFFER_SIZE + 1);
	if (!str_aux)
		return (0);
	while (!ft_strchr(buffer, '\n') && nbytes > 0)
	{
		str_aux = ft_memset(str_aux, 0, BUFFER_SIZE);
		nbytes = read(fd, str_aux, BUFFER_SIZE);
		if (nbytes < 1)
			break ;
		str_aux[BUFFER_SIZE] = '\0';
		buffer = ft_strjoin(buffer, str_aux);
	}
	free (str_aux);
	if (nbytes < 0)
		return (0);
	else
		return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (0);
	buffer = read_buf(fd, buffer);
	if (!buffer)
		return (0);
	line = pickline(buffer);
	buffer = rest(buffer);
	return (line);
}
