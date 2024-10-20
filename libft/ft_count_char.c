/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:13:03 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/01 14:14:39 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *str, char c)
{
	int	cnt_num;

	cnt_num = 0;
	while (*str)
	{
		if (*str == c)
			cnt_num ++;
		str ++;
	}
	return (cnt_num);
}
