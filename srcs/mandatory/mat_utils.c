/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:14 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/mat.h"
#include "../../includes/mandatory/vec.h"

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
