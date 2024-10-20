/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:11 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/23 17:29:14 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"

t_vec	calc_diffuse_light(t_l *l, t_ray *r, t_ray *new_r, t_vec l_sum)
{
	double	brightness;

	brightness = dot_vec(new_r->dir, r->basis[2]);
	brightness = fmax(brightness, 0);
	return (sum_vec(l_sum, mul_vec(brightness, l->color)));
}

t_vec	calc_specular_light(t_l *l, t_ray *r, t_ray *new_r, t_vec l_sum)
{
	t_vec	reflect;
	double	factor;
	double	brightness;

	factor = 2 * dot_vec(r->basis[2], new_r->dir) / vec_size(r->basis[2]);
	reflect = sum_vec(mul_vec(-1, new_r->dir), mul_vec(factor, r->basis[2]));
	brightness = dot_vec(reflect, mul_vec(-1, r->dir));
	brightness /= (vec_size(reflect) * vec_size(r->dir));
	brightness = pow(max_d(brightness, 0), SHINE_NUM);
	brightness = fmax(brightness, 0);
	return (sum_vec(l_sum, mul_vec(brightness, l->color)));
}

void	apply_phong_model(\
	t_data *data, t_ray *ray, t_vec *light, t_vec refl_col)
{
	double	refl_r;
	t_vec	ambient_light;
	t_vec	light_sum[4];

	ambient_light = data->obj.a.color;
	refl_r = (double) data->light_val[1] / 100;
	light_sum[0] = gen_reflection_color(ray->color, light[0]);
	light_sum[1] = gen_reflection_color(ray->color, light[1]);
	light_sum[2] = gen_reflection_color(ray->color, ambient_light);
	light_sum[3] = gen_reflection_color(ray->color, mul_vec(refl_r, refl_col));
	ray->color = sum_vec(light_sum[0], sum_vec(light_sum[1], light_sum[2]));
	ray->color = trim_max_light(ray->color);
	ray->color = mul_vec(1 - refl_r, ray->color);
	ray->color = sum_vec(ray->color, light_sum[3]);
	ray->color = trim_max_light(ray->color);
}
