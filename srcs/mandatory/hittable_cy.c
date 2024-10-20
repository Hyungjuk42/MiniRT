/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:06 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"

static void	hit_cy_edge(t_ray *ray, t_cy *cy, double *ret, double h)
{
	t_vec	cap_center;
	t_vec	edge_pt;
	t_vec	h_vec;
	double	t;

	h_vec = mul_vec(h, unit_vec(cy->normal));
	cap_center = sum_vec(cy->center, h_vec);
	t = find_point_pl(ray, cap_center, cy->normal);
	edge_pt = sum_vec(ray->orig, mul_vec(t, ray->dir));
	if (t > 0 && vec_size(sub_vec(edge_pt, cap_center)) <= cy->rad + 1e-4)
	{
		if (*ret > 0)
			*ret = min_d(*ret, t);
		else
			*ret = t;
	}
}

static void	set_nearest_ray(t_ray *ray, t_vec normal, double root, int *ret)
{
	if (root > 0 && root < ray->ray_max)
	{
		ray->ray_max = root;
		ray->normal = normal;
		*ret = 1;
	}
}

static void	chk_valid_root(t_ray *ray, t_cy *cy, double *ret)
{
	t_vec	ray_point;
	t_vec	surface_vec;
	double	disc;

	ray_point = sum_vec(ray->orig, mul_vec(*ret, ray->dir));
	surface_vec = sub_vec(ray_point, cy->center);
	if (*ret > 0)
	{
		disc = dot_vec(surface_vec, cy->normal) / vec_size(cy->normal);
		if (fabs(disc) > cy->h + 1e-4)
			*ret = -1;
	}
}

int	chk_hittable_cy(t_ray *ray, t_cy *cy)
{
	t_vec	d_n;
	t_vec	c_n;
	t_vec	c_p;
	double	e[4];
	int		ret;

	d_n = cross_vec(ray->dir, cy->normal);
	c_n = cross_vec(sub_vec(ray->orig, cy->center), cy->normal);
	e[0] = pow(vec_size(d_n), 2);
	e[1] = dot_vec(d_n, c_n);
	e[2] = pow(vec_size(c_n), 2) - pow(cy->rad, 2);
	e[3] = solve_root_equation(e);
	ret = 0;
	chk_valid_root(ray, cy, &e[3]);
	c_p = sub_vec(sum_vec(ray->orig, mul_vec(e[3], ray->dir)), cy->center);
	set_nearest_ray(ray, \
	sub_vec(c_p, mul_vec(dot_vec(c_p, cy->normal), cy->normal)), e[3], &ret);
	hit_cy_edge(ray, cy, &e[3], cy->h);
	set_nearest_ray(ray, unit_vec(cy->normal), e[3], &ret);
	hit_cy_edge(ray, cy, &e[3], -cy->h);
	set_nearest_ray(ray, unit_vec(cy->normal), e[3], &ret);
	if (ret)
		ray->color = cy->color;
	return (ret);
}
