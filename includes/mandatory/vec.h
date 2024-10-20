/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:36 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:46 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  VEC_H
# define VEC_H

# define X	0
# define Y	1
# define Z	2
# define R	0
# define G	1
# define B	2

typedef struct s_vec
{
	double	e[3];
}	t_vec;

// vector
void	set_vec(t_vec *vec, double x, double y, double z);
t_vec	gen_vec(double x, double y, double z);
t_vec	unit_vec(t_vec rhs);
t_vec	sum_vec(t_vec lhs, t_vec rhs);
t_vec	sub_vec(t_vec lhs, t_vec rhs);
t_vec	mul_vec(double lhs, t_vec rhs);
t_vec	div_vec(double lhs, t_vec rhs);
double	dot_vec(t_vec lhs, t_vec rhs);
t_vec	cross_vec(t_vec lhs, t_vec rhs);
double	vec_size(t_vec rhs);

// vector utils
t_vec	gen_reflection_color(t_vec surface_color, t_vec light);
void	set_face_front_normal(t_vec *normal, t_vec dir);

#endif