/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:37:20 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/13 23:27:31 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ret;

	ret = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (ret);
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (ret);
}
