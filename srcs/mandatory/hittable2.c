/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:10 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"

static void	chk_valid_root(t_ray *ray, t_hb *hb, double *ret)
{
	t_vec	ray_point;
	t_vec	surface_vec;
	double	disc;

	ray_point = sum_vec(ray->orig, mul_vec(*ret, ray->dir));
	surface_vec = sub_vec(ray_point, hb->center);
	if (*ret > 0)
	{
		disc = dot_vec(surface_vec, hb->normal) / vec_size(hb->normal);
		if (fabs(disc) > hb->h + 1e-4)
			*ret = -1;
	}
}

static double	solve_root_equation_hb(t_ray *ray, t_hb *hb, double *e)
{
	double	disc;
	double	ret;

	disc = e[1] * e[1] - e[0] * e[2];
	if (disc < 0)
		return (-1.0);
	if (e[0] > 0)
		ret = (-e[1] - sqrt(disc)) / e[0];
	else
		ret = (-e[1] + sqrt(disc)) / e[0];
	if (ret > 0)
		chk_valid_root(ray, hb, &ret);
	if (ret > 0)
		return (ret);
	if (e[0] > 0)
		ret = (-e[1] + sqrt(disc)) / e[0];
	else
		ret = (-e[1] - sqrt(disc)) / e[0];
	if (ret > 0)
		chk_valid_root(ray, hb, &ret);
	return (ret);
}

int	chk_hittable_hb(t_ray *ray, t_hb *hb)
{
	t_vec	mata_d;
	t_vec	mata_c;
	t_vec	mata_a_tr_c;
	t_vec	v_sub_c;
	double	e[4];

	mata_d = cross_mat2vec(&hb->lin_trans, ray->dir);
	mata_c = cross_mat2vec(&hb->lin_trans, hb->center);
	mata_a_tr_c = sum_vec(cross_mat2vec(&hb->lin_trans_tr, hb->center), mata_c);
	e[0] = dot_vec(ray->dir, mata_d);
	e[1] = dot_vec(ray->dir, mata_a_tr_c) * -0.5 + \
	dot_vec(ray->dir, cross_mat2vec(&hb->lin_trans, ray->orig));
	e[2] = dot_vec(hb->center, mata_c) - 1 - dot_vec(ray->orig, \
	sub_vec(mata_a_tr_c, cross_mat2vec(&hb->lin_trans, ray->orig)));
	e[3] = solve_root_equation_hb(ray, hb, e);
	if (e[3] <= 0 || e[3] >= ray->ray_max)
		return (0);
	ray->ray_max = e[3];
	v_sub_c = sub_vec(sum_vec(ray->orig, mul_vec(e[3], ray->dir)), hb->center);
	ray->normal = cross_mat2vec(&hb->lin_trans_tr, mul_vec(2, v_sub_c));
	ray->normal = unit_vec(ray->normal);
	ray->color = hb->color;
	return (1);
}
