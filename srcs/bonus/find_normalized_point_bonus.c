/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normalized_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:04 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 16:56:45 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"

t_vec	find_normalized_point_pl(t_pl *pl, t_vec point)
{
	t_vec	basis_v[3];
	t_vec	op;
	double	px;
	double	py;

	trans_mat2vec_arr(&pl->on_basis, basis_v);
	op = sub_vec(point, pl->point);
	px = fmod(dot_vec(basis_v[X], op), N_FACTOR * 2) / (N_FACTOR * 2);
	py = fmod(dot_vec(basis_v[Y], op), N_FACTOR * 4) / (N_FACTOR * 4);
	if (px < 0)
		px += 1;
	if (py < 0)
		py += 1;
	if (pl->matl == MAT_BUMP)
		py = fmod(py * 2, 1);
	return (gen_vec(px, py, 0));
}

t_vec	find_normalized_point_sp(t_sp *sp, t_vec point)
{
	t_vec	basis_v[3];
	t_vec	op;
	double	sin_cos[2];
	double	px;
	double	py;

	trans_mat2vec_arr(&sp->on_basis, basis_v);
	op = sub_vec(point, sp->center);
	px = fmod(dot_vec(op, basis_v[2]) + sp->rad, sp->rad * 2) / (sp->rad * 2);
	make_triangular_on_basis(&sp->on_basis, op, sin_cos);
	py = acos(sin_cos[1]) / (2 * M_PI);
	if (sin_cos[0] < 0)
		py = 1 - py;
	return (gen_vec(px, py, 0));
}

t_vec	find_normalized_point_cy(int ratio, t_ray *ray, t_cy *cy, t_point *p)
{
	t_vec	c_p;
	double	sin_cos[2];
	double	total_h;
	double	px;
	double	py;

	c_p = sum_vec(ray->orig, mul_vec(ray->ray_max, ray->dir));
	c_p = sub_vec(c_p, cy->center);
	make_triangular_on_basis(&cy->on_basis, c_p, sin_cos);
	py = acos(sin_cos[1]) / (2 * M_PI);
	if (sin_cos[0] < 0)
		py = 1 - py;
	total_h = 2 * (cy->rad + cy->h) / ratio;
	px = fmod(p->h, total_h) / total_h;
	return (gen_vec(px, py, 0));
}

t_vec	find_normalized_point_hb(t_hb *hb, t_vec point)
{
	t_vec	basis_v[3];
	t_vec	op;
	double	sin_cos[2];
	double	px;
	double	py;

	trans_mat2vec_arr(&hb->on_basis, basis_v);
	op = sub_vec(point, hb->center);
	px = fmod(dot_vec(op, basis_v[2]) + hb->h, hb->h * 2) / (hb->h * 2);
	make_triangular_on_basis(&hb->on_basis, op, sin_cos);
	py = acos(sin_cos[1]) / (2 * M_PI);
	if (sin_cos[0] < 0)
		py = 1 - py;
	return (gen_vec(px, py, 0));
}
