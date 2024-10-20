/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:34 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:48 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  RAY_H
# define RAY_H

# include "vec.h"

# define DEPTH 1

typedef struct s_ray
{
	t_vec	orig;
	t_vec	dir;
	t_vec	color;
	t_vec	normal;
	double	ray_max;
	int		obj_order;
}	t_ray;

t_ray	gen_ray(t_vec orig, t_vec dir);
t_vec	at(double lhs, const t_ray *rhs);

#endif