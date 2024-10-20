/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:38:37 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/11/30 09:54:46 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_str(char const *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	res = (char *) malloc(sizeof(char) * len);
	if (res == NULL)
		exit(1);
	while (i < len)
	{
		res[i] = str[len - i - 1];
		i ++;
	}
	return (res);
}
