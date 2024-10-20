/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:10:15 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/14 07:52:14 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0 - 1;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == 0)
		return (0);
	while (*(s + ++i))
		*(ret + i) = f(i, *(s + i));
	ret [i] = '\0';
	return (ret);
}
