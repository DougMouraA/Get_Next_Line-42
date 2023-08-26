/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoura-a <dmoura-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:55:10 by dmoura-a          #+#    #+#             */
/*   Updated: 2022/08/17 13:19:23 by dmoura-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*rest(char *buffer);
char	*pickline(char *buffer);
char	*read_buf(int fd, char *buffer);
char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);

#endif