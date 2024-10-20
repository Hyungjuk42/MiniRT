/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:25 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:12 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/mandatory/ray.h"

t_ray	gen_ray(t_vec orig, t_vec dir)
{
	t_ray	ret;

	ret.dir = dir;
	ret.orig = sum_vec(orig, mul_vec(1e-4, dir));
	ret.color = gen_vec(-1, -1, -1);
	ret.normal = gen_vec(0, 0, 0);
	ret.ray_max = INFINITY;
	ret.obj_order = -1;
	return (ret);
}

t_vec	at(double lhs, const t_ray *rhs)
{
	t_vec	dir;

	dir = mul_vec(lhs, rhs->dir);
	return (sum_vec(rhs->orig, dir));
}
