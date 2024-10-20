/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:51:33 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:23:50 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset2(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	i = 0 - 1;
	s = (unsigned char *)b;
	while (++i < len)
		s[i] = (unsigned char)c;
	return (b);
}

char	*ft_strjoin2(t_fdlist **cur, char *buf)
{
	size_t	size;
	size_t	i;
	char	*make;

	i = 0 - 1;
	if (!(*cur)->size && !(*cur)->rd_size)
		return (0);
	size = (*cur)->size + (*cur)->rd_size;
	make = (char *)malloc(sizeof(char) * (size + 1));
	if (!make)
	{
		free((*cur)->str);
		return (0);
	}
	while (++i < (*cur)->size)
		*(make + i) = *((*cur)->str + i);
	while (i < size)
		*(make + i++) = *buf++;
	*(make + i) = '\0';
	(*cur)->size = size;
	if ((*cur)->str)
		free((*cur)->str);
	return (make);
}

size_t	ft_memchr2(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	size_t			size;

	size = 0;
	ss = (unsigned char *)s;
	while (n--)
	{
		size++;
		if (*ss == (unsigned char)c)
			return (size);
		ss++;
	}
	return (0);
}

char	*ft_strdup2(t_fdlist **cur, size_t nl_size)
{
	char	*dup;
	size_t	size;
	size_t	i;

	i = 0 - 1;
	if (!nl_size && !(*cur)->size)
		return (0);
	if (nl_size > 0)
		size = nl_size;
	else
		size = (*cur)->size;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == 0)
		return (0);
	while (++i < size)
		*(dup + i) = *((*cur)->str + i);
	*(dup + i) = '\0';
	(*cur)->size -= i;
	ft_memmove2((*cur)->str, ((*cur)->str + i), (*cur)->size);
	ft_memset2(((*cur)->str + (*cur)->size), '\0', i);
	(*cur)->rd_size = 0;
	return (dup);
}

void	*ft_memmove2(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
		i = len;
	else
		i = 0 - 1;
	if (dst > src)
		while (i--)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	else
		while (++i < len)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	return (dst);
}
