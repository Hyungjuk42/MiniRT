/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:31 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 16:50:57 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/bonus/miniRT_bonus.h"

double	min_d(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	max_d(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_atoi_hard(const char *str, int idx)
{
	long long	num;
	int			s;

	num = 0;
	s = 1;
	while (*str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		idx ++;
	}
	while (str[idx] == '0')
		str ++;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		num *= 10;
		num += str[idx] - '0';
		idx ++;
	}
	if (idx > 12 || (num * s) < INT32_MIN || (num * s) > INT32_MAX || \
	str[idx] != 0 || (idx > 0 && (str[idx - 1] == '+' || str[idx - 1] == '-')))
		handling_error(WRONG_ARG);
	return (num * s);
}

int	set_int_range(char *str, int min, int max)
{
	int	ret;

	ret = ft_atoi_hard(str, 0);
	if (ret < min || ret > max)
	{
		printf("%d\n", ret);
		handling_error(OUT_OF_BND);
	}
	return (ret);
}

t_bump	*set_bump_map(t_data *data, char *str)
{
	int		bump_num;
	t_bump	*ret;

	bump_num = set_int_range(str, 0, data->bump_num - 1);
	ret = ft_lstfind(data->bumpmap, bump_num);
	if (!ret)
		handling_error(OUT_OF_BND);
	return (ret);
}
