/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcki <youngcki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:39:41 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/09/24 17:34:46 by youngcki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*ret;
	char	*make;

	size = ft_strlen(s1);
	size += ft_strlen(s2);
	make = (char *)malloc(sizeof(char) * (size + 1));
	if (make == 0)
		return (0);
	ret = make;
	while (s1 && *s1)
		*make++ = *s1++;
	while (s2 && *s2)
		*make++ = *s2++;
	*make = '\0';
	return (ret);
}
