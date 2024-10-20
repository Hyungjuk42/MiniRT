/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:31 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/13 21:24:04 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dest_len >= size)
		return (src_len + size);
	else
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i++ < size - 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (dest_len + src_len);
}
