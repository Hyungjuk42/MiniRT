/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:46:10 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/14 09:36:08 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	i;
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(s1);
	while (is_set(*(s1 + left), set))
		left++;
	while (right > left && is_set(*(s1 + right - 1), set))
		right--;
	ret = (char *)malloc(sizeof(char) * (right - left + 1));
	if (ret == 0)
		return (0);
	i = 0 - 1;
	while (++i < right - left)
		*(ret + i) = *(s1 + left + i);
	*(ret + i) = '\0';
	return (ret);
}

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
