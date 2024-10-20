/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:08 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"

void	hit_cy_edge(t_ray *ray, t_cy *cy, double *ret, double h);
void	chk_valid_root(t_ray *ray, t_cy *cy, double *ret);

int	chk_hittable_sp(t_ray *ray, t_sp *sp)
{
	t_vec	oc;
	double	e[3];
	double	root;
	t_vec	point;

	oc = sub_vec(ray->orig, sp->center);
	e[0] = dot_vec(ray->dir, ray->dir);
	e[1] = dot_vec(oc, ray->dir);
	e[2] = dot_vec(oc, oc) - sp->rad * sp->rad;
	root = solve_root_equation(e);
	if (root <= 0 || root >= ray->ray_max)
		return (0);
	ray->ray_max = root;
	point = sum_vec(ray->orig, mul_vec(root, ray->dir));
	ray->normal = unit_vec(sub_vec(point, sp->center));
	ray->color = sp->color;
	return (1);
}

int	chk_hittable_pl(t_ray *ray, t_pl *pl)
{
	double	root;

	root = find_point_pl(ray, pl->point, pl->normal);
	if (root <= 0 || root >= ray->ray_max)
		return (0);
	ray->ray_max = root;
	ray->normal = pl->normal;
	ray->color = pl->color;
	return (1);
}

double	find_point_pl(t_ray *ray, t_vec point, t_vec normal)
{
	double	tmp;
	double	ret;

	tmp = dot_vec(normal, ray->dir);
	if (tmp == 0)
		return (-1);
	ret = dot_vec(normal, sub_vec(ray->orig, point)) * -1;
	ret /= tmp;
	return (ret);
}

double	solve_root_equation(double *e)
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
		return (ret);
	if (e[0] > 0)
		ret = (-e[1] + sqrt(disc)) / e[0];
	else
		ret = (-e[1] - sqrt(disc)) / e[0];
	return (ret);
}
