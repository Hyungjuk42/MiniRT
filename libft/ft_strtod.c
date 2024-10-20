/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:14:17 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/11/30 12:14:39 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"

static double	ft_stod_decimal_part(char *str)
{
	double	res;
	int		exp;

	res = 0;
	exp = 1;
	if (*str == '\0')
		return (0);
	str ++;
	if (*str == '\0')
		return (NAN);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (NAN);
		res += pow(0.1, exp) * (*str - '0');
		exp ++;
		str ++;
	}
	return (res);
}

double	ft_strtod(char *str)
{
	int		sign;
	double	ret;
	double	decimal;

	sign = 1;
	ret = 0;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '+' || str[0] == '-')
		str ++;
	if (*str == '\0' || *str == '.')
		return (NAN);
	while (*str && *str != '.')
	{
		if (ft_isdigit(*str) == 0)
			return (NAN);
		ret = ret * 10 + *str - '0';
		str ++;
	}
	decimal = ft_stod_decimal_part(str);
	if (decimal == NAN)
		return (NAN);
	ret += decimal;
	return ((ret) * sign);
}
