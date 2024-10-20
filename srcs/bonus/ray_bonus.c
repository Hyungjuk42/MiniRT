/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:25 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/23 15:59:22 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../libft/libft.h"
#include "../../includes/bonus/ray_bonus.h"

t_ray	gen_ray(t_vec orig, t_vec dir)
{
	t_ray	ret;

	ft_memset(&ret, 0, sizeof(t_ray));
	ret.dir = dir;
	ret.orig = sum_vec(orig, mul_vec(1e-4, dir));
	ret.color = gen_vec(-1, -1, -1);
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

void	get_tangents(t_ray *ray, t_vec n)
{
	t_vec	n_factor;

	n_factor = mul_vec(dot_vec(ray->dir, unit_vec(n)), n);
	if (dot_vec(n_factor, ray->dir) > 0)
		n_factor = mul_vec(-1, n_factor);
	ray->basis[X] = sum_vec(ray->dir, n_factor);
	if (vec_size(ray->basis[X]) == 0)
		ray->basis[X] = gen_vec(2 * n_factor.e[1] * n_factor.e[2], \
								-n_factor.e[0] * n_factor.e[2], \
								-n_factor.e[0] * n_factor.e[1]);
	ray->basis[X] = unit_vec(ray->basis[X]);
	ray->basis[Y] = unit_vec(cross_vec(n, ray->basis[X]));
}
