/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:20:24 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/14 03:20:26 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (*(needle + i) && i < len)
		{
			if (*(haystack + i) != *(needle + i))
				break ;
			i++;
		}
		if (*(needle + i) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
