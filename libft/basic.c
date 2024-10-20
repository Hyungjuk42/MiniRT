/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:31:02 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:23:29 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	rec_print(long long n, int *i, char *base)
{
	char	p;
	int		base_len;

	base_len = ft_strlen(base);
	p = base[n % base_len];
	if (n)
	{
		n /= base_len;
		if (rec_print(n, i, base) == -1)
			return (-1);
		if (write(1, &p, 1) == -1)
			return (-1);
		*i += 1;
	}
	return (0);
}

int	p_rec_print(unsigned long n, int *i, char *base)
{
	char	p;
	int		base_len;

	base_len = ft_strlen(base);
	p = base[n % base_len];
	if (n)
	{
		n /= base_len;
		if (rec_print(n, i, base) == -1)
			return (-1);
		if (write(1, &p, 1) == -1)
			return (-1);
		*i += 1;
	}
	return (0);
}
