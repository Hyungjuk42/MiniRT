/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:02 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/vec.h"

void	set_vec(t_vec *vec, double x, double y, double z)
{
	vec->e[X] = x;
	vec->e[Y] = y;
	vec->e[Z] = z;
}

t_vec	gen_vec(double x, double y, double z)
{
	t_vec	ret;

	set_vec(&ret, x, y, z);
	return (ret);
}

t_vec	unit_vec(t_vec rhs)
{
	t_vec	ret;
	double	size;

	size = vec_size(rhs);
	if (size == 0)
		handling_error(NORM_FAIL);
	ret = gen_vec(rhs.e[X] / size, rhs.e[Y] / size, rhs.e[Z] / size);
	return (ret);
}

t_vec	sum_vec(t_vec lhs, t_vec rhs)
{
	t_vec	ret;

	ret.e[X] = lhs.e[X] + rhs.e[X];
	ret.e[Y] = lhs.e[Y] + rhs.e[Y];
	ret.e[Z] = lhs.e[Z] + rhs.e[Z];
	return (ret);
}

t_vec	sub_vec(t_vec lhs, t_vec rhs)
{
	t_vec	ret;

	ret = mul_vec(-1, rhs);
	return (sum_vec(lhs, ret));
}
