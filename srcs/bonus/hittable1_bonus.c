/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:07 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:58:29 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../mlx/mlx.h"

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
	ray->basis[2] = unit_vec(sub_vec(point, sp->center));
	if (sp->matl == MAT_MONO)
		ray->color = sp->color;
	else if (sp->matl == MAT_CHECK)
		checker_board(find_normalized_point_sp(sp, point), ray, sp->color);
	else if (sp->matl == MAT_BUMP)
		normal_map(sp->bump, find_normalized_point_sp(sp, point), ray);
	return (1);
}

int	chk_hittable_pl(t_ray *ray, t_pl *pl)
{
	double	root;
	t_vec	point;

	root = find_point_pl(ray, pl->point, pl->normal);
	if (root <= 0 || root >= ray->ray_max)
		return (0);
	ray->ray_max = root;
	ray->basis[2] = pl->normal;
	point = sum_vec(ray->orig, mul_vec(root, ray->dir));
	if (pl->matl == MAT_MONO)
		ray->color = pl->color;
	else if (pl->matl == MAT_CHECK)
		checker_board(find_normalized_point_pl(pl, point), ray, pl->color);
	else if (pl->matl == MAT_BUMP)
		normal_map(pl->bump, find_normalized_point_pl(pl, point), ray);
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
