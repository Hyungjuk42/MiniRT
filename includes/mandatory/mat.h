/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:30 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:53 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MAT_H
# define MAT_H

# include "vec.h"

typedef struct s_mat
{
	double	e[3][3];
}	t_mat;

// mat
void	set_mat_rotation_part(t_mat *mat, t_vec v1, t_vec v2, t_vec v3);
void	gen_diagonal_mat(t_mat *res, t_vec scaler);
t_mat	cross_mat2mat(t_mat *lhs, t_mat *rhs);
t_vec	cross_mat2vec(t_mat *lhs, t_vec rhs);
t_mat	transpose_mat(t_mat *rhs);

// mat_utils
void	gen_on_basis(t_mat *res, t_vec up, t_vec m_z);

#endif