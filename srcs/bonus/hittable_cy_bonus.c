/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_cy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:06 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:58:48 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"

static void	hit_cy_edge(t_ray *ray, t_cy *cy, t_point *p, double h)
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
		p->rad = vec_size(sub_vec(edge_pt, cap_center));
		if (p->root > 0)
			p->root = min_d(p->root, t);
		else
			p->root = t;
	}
}

static int	set_nearest_ray(t_ray *ray, t_cy *cy, t_point *p, int flag)
{
	double	root;

	root = p->root;
	if (root > 0 && root < ray->ray_max)
	{
		ray->ray_max = root;
		ray->basis[2] = unit_vec(p->normal);
		if (cy->matl == MAT_MONO)
			return (1);
		if (flag != 0 && p->rad == 0)
			ray->color = cy->color;
		else if (flag == 0)
			p->h = fabs(dot_vec(p->c_p, cy->normal) - cy->h) + cy->rad;
		else if (flag == 1)
			p->h = p->rad;
		else
			p->h = 2 * (cy->h + cy->rad) - p->rad;
		return (1);
	}
	return (0);
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

void	set_cylinder_color(t_ray *ray, t_cy *cy, t_point *p, int hit)
{
	t_vec	normalized_point;
	int		ratio;

	if (hit == 0)
		return ;
	if (cy->matl == MAT_MONO)
		ray->color = cy->color;
	else if (cy->matl == MAT_CHECK)
	{
		ratio = 1;
		if (cy->rad < cy->h)
			ratio = (int)(cy->h / cy->rad);
		if (ratio == 0)
			ratio = 1;
		normalized_point = find_normalized_point_cy(ratio, ray, cy, p);
		checker_board(normalized_point, ray, cy->color);
	}
	else if (cy->matl == MAT_BUMP)
	{
		normalized_point = find_normalized_point_cy(1, ray, cy, p);
		normal_map(cy->bump, normalized_point, ray);
	}
}

int	chk_hittable_cy(t_ray *ray, t_cy *cy)
{
	t_vec	d_n;
	t_vec	c_n;
	t_point	p;
	double	e[3];
	int		hit;

	d_n = cross_vec(ray->dir, cy->normal);
	c_n = cross_vec(sub_vec(ray->orig, cy->center), cy->normal);
	e[0] = pow(vec_size(d_n), 2);
	e[1] = dot_vec(d_n, c_n);
	e[2] = pow(vec_size(c_n), 2) - pow(cy->rad, 2);
	p.root = solve_root_equation(e);
	hit = 0;
	chk_valid_root(ray, cy, &p.root);
	p.c_p = sub_vec(sum_vec(ray->orig, mul_vec(p.root, ray->dir)), cy->center);
	p.normal = sub_vec(p.c_p, mul_vec(dot_vec(p.c_p, cy->normal), cy->normal));
	hit |= set_nearest_ray(ray, cy, &p, 0);
	hit_cy_edge(ray, cy, &p, cy->h);
	p.normal = unit_vec(cy->normal);
	hit |= set_nearest_ray(ray, cy, &p, 1);
	hit_cy_edge(ray, cy, &p, -cy->h);
	hit |= set_nearest_ray(ray, cy, &p, 2);
	set_cylinder_color(ray, cy, &p, hit);
	return (hit);
}
