/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:48:52 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:23:36 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define DECIMAL "0123456789"
#define L_HEX "0123456789abcdef"

int	f_char(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*i += 1;
	return (0);
}

int	f_string(char *s, int *i)
{
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*i += 6;
		return (6);
	}
	while (*s)
	{
		if (write(1, s, 1) == -1)
			return (-1);
		s++;
		*i += 1;
	}
	return (0);
}

int	f_pointer(void *s, int *i)
{
	unsigned long	n;

	n = (unsigned long)s;
	if (write(1, "0x", 2) == -1)
		return (-1);
	*i += 2;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		*i += 1;
	}
	p_rec_print(n, i, L_HEX);
	return (0);
}

int	f_decimal(int d, int *i)
{
	long long	n;

	n = d;
	if (n == 0)
	{
		if (write(1, DECIMAL, 1) == -1)
			return (-1);
		*i += 1;
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		*i += 1;
		n *= -1;
	}
	if (rec_print(n, i, DECIMAL) == -1)
		return (-1);
	return (0);
}

int	f_uint(unsigned int d, int *i)
{
	if (d == 0)
	{
		if (write(1, DECIMAL, 1) == -1)
			return (-1);
		*i += 1;
	}
	if (rec_print(d, i, DECIMAL) == -1)
		return (-1);
	return (0);
}
