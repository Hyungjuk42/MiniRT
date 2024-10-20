/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:58:17 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:23:40 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define U_HEX "0123456789ABCDEF"
#define L_HEX "0123456789abcdef"

int	f_lowhex(unsigned int n, int *i)
{
	if (n == 0)
	{
		if (write(1, L_HEX, 1) == -1)
			return (-1);
		*i += 1;
	}
	if (rec_print(n, i, L_HEX) == -1)
		return (-1);
	return (0);
}

int	f_uphex(unsigned int n, int *i)
{
	if (n == 0)
	{
		if (write(1, U_HEX, 1) == -1)
			return (-1);
		*i += 1;
	}
	if (rec_print(n, i, U_HEX) == -1)
		return (-1);
	return (0);
}

int	f_percent(int *i)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	*i += 1;
	return (0);
}
