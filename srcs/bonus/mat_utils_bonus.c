/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:15 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/mat_bonus.h"
#include "../../includes/bonus/vec_bonus.h"

void	gen_on_basis(t_mat *res, t_vec up, t_vec m_z)
{
	t_vec	tmp;
	t_vec	u;
	t_vec	v;
	t_vec	n;

	n = unit_vec(m_z);
	tmp = cross_vec(up, n);
	if (vec_size(tmp) == 0 && dot_vec(n, up) > 0)
		u = gen_vec(1, 0, 0);
	else if (vec_size(tmp) == 0 && dot_vec(n, up) < 0)
		u = gen_vec(-1, 0, 0);
	else
		u = unit_vec(cross_vec(up, n));
	v = cross_vec(n, u);
	set_mat_rotation_part(res, u, v, n);
}

void	gen_lin_trans_mat(t_hb *hb)
{
	t_mat	res;
	t_mat	res_trans;
	t_mat	scale_mat;

	gen_on_basis(&res, gen_vec(0, 1, 0), hb->normal);
	res_trans = transpose_mat(&res);
	gen_diagonal_mat(&scale_mat, hb->scaler);
	res_trans = cross_mat2mat(&res_trans, &scale_mat);
	hb->lin_trans = cross_mat2mat(&res_trans, &res);
	hb->lin_trans_tr = transpose_mat(&hb->lin_trans);
}

void	make_triangular_on_basis(t_mat *lhs, t_vec rhs, double res[2])
{
	t_vec	basis_v[3];
	double	n_factor;

	trans_mat2vec_arr(lhs, basis_v);
	res[0] = dot_vec(basis_v[1], rhs);
	res[1] = dot_vec(basis_v[0], rhs);
	n_factor = sqrt(pow(res[0], 2) + pow(res[1], 2));
	res[0] /= n_factor;
	res[1] /= n_factor;
}
