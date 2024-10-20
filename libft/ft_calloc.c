/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:08:27 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/13 13:37:06 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ret;

	i = 0;
	ret = (void *)malloc(sizeof(char) * size * count);
	if (ret == NULL)
		exit(1);
	while (i < count * size)
		*(char *)(ret + i++) = 0;
	return (ret);
}
