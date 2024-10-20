/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:56 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/18 19:31:16 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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
