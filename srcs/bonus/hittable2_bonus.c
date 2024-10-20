/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:10 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:58:39 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"

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
	t_vec	dt_a;
	t_vec	ct_a;
	t_vec	v;
	t_vec	v_sub_c;
	double	e[4];

	dt_a = cross_mat2vec(&hb->lin_trans_tr, ray->dir);
	ct_a = cross_mat2vec(&hb->lin_trans_tr, sub_vec(ray->orig, hb->center));
	e[0] = dot_vec(dt_a, ray->dir);
	e[1] = dot_vec(dt_a, sub_vec(ray->orig, hb->center));
	e[2] = dot_vec(ct_a, sub_vec(ray->orig, hb->center)) - 1;
	e[3] = solve_root_equation_hb(ray, hb, e);
	if (e[3] <= 0 || e[3] >= ray->ray_max)
		return (0);
	ray->ray_max = e[3];
	v = sum_vec(ray->orig, mul_vec(e[3], ray->dir));
	v_sub_c = sub_vec(v, hb->center);
	ray->basis[2] = unit_vec(cross_mat2vec(&hb->lin_trans_tr, v_sub_c));
	if (hb->matl == MAT_MONO)
		ray->color = hb->color;
	else if (hb->matl == MAT_CHECK)
		checker_board(find_normalized_point_hb(hb, v), ray, hb->color);
	else if (hb->matl == MAT_BUMP)
		normal_map(hb->bump, find_normalized_point_hb(hb, v), ray);
	return (1);
}
