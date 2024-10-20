/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:53:11 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/09/13 20:02:48 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0 - 1;
	if (ft_strlen(s) > start)
		while (start--)
			s++;
	else
		len = 0;
	if (ft_strlen(s) <= len)
		len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	while (++i < len && *(s + i))
		*(ret + i) = *(s + i);
	*(ret + i) = '\0';
	return (ret);
}
