/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:34 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 16:50:56 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../libft/libft.h"
#include "../../includes/bonus/vec_bonus.h"

t_vec	mul_vec(double lhs, t_vec rhs)
{
	t_vec	ret;

	set_vec(&ret, lhs * rhs.e[X], lhs * rhs.e[Y], lhs * rhs.e[Z]);
	return (ret);
}

t_vec	div_vec(double lhs, t_vec rhs)
{
	if (lhs == 0)
	{
		printf("Error: division by zero\n");
		exit(1);
	}
	return (mul_vec(1 / lhs, rhs));
}

double	dot_vec(t_vec lhs, t_vec rhs)
{
	double	ret;

	ret = lhs.e[X] * rhs.e[X] + lhs.e[Y] * rhs.e[Y] + lhs.e[Z] * rhs.e[Z];
	return (ret);
}

t_vec	cross_vec(t_vec lhs, t_vec rhs)
{
	t_vec	ret;

	ret.e[X] = lhs.e[Y] * rhs.e[Z] - lhs.e[Z] * rhs.e[Y];
	ret.e[Y] = lhs.e[Z] * rhs.e[X] - lhs.e[X] * rhs.e[Z];
	ret.e[Z] = lhs.e[X] * rhs.e[Y] - lhs.e[Y] * rhs.e[X];
	return (ret);
}

double	vec_size(t_vec rhs)
{	
	double	size;

	size = pow(rhs.e[X], 2) + pow(rhs.e[Y], 2) + pow(rhs.e[Z], 2);
	size = sqrt(size);
	return (size);
}
