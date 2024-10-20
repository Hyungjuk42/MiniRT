/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:27 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:54 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  RAY_BONUS_H
# define RAY_BONUS_H

# include "vec_bonus.h"

# define DEPTH 20

typedef struct s_ray
{
	t_vec	orig;
	t_vec	dir;
	t_vec	color;
	t_vec	basis[3];
	double	ray_max;
	int		obj_order;
}	t_ray;

t_ray	gen_ray(t_vec orig, t_vec dir);
t_vec	at(double lhs, const t_ray *rhs);
void	get_tangents(t_ray *ray, t_vec n);
t_vec	gen_rand_dir(t_vec normal);

#endif