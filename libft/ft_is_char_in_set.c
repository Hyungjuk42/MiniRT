/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_in_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:38:29 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/11/29 17:39:48 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++ set;
	}
	return (0);
}
