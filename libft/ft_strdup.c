/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:03:28 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/10/09 00:45:38 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*dup;

	if (!s1)
		return (0);
	dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dup == 0)
		return (0);
	ret = dup;
	while (*s1)
		*dup++ = *s1++;
	*dup = '\0';
	return (ret);
}
