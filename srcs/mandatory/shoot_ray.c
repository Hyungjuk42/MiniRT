/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:27 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/mlx_utils.h"

static t_vec	sum_all_light(\
				t_data *data, t_list *node, t_ray *ray, t_vec orig)
{
	t_l		*light;
	t_vec	light_sum;
	t_ray	new_ray;
	double	brightness;

	light_sum = gen_vec(0, 0, 0);
	while (node)
	{
		light = (t_l *) node->content;
		new_ray = gen_ray(orig, unit_vec(sub_vec(light->point, orig)));
		new_ray.ray_max = vec_size(sub_vec(light->point, orig));
		if (dot_vec(new_ray.dir, ray->normal) > 0 && \
			!check_hittable_to_all_obj(data, &new_ray))
		{
			brightness = dot_vec(new_ray.dir, ray->normal);
			brightness = fmax(brightness, 0);
			light_sum = sum_vec(light_sum, mul_vec(brightness, light->color));
		}
		node = node->next;
	}
	light_sum = sum_vec(light_sum, data->obj.a.color);
	return (light_sum);
}

static void	ray_tracing_recur(t_data *data, t_ray *ray, int depth)
{
	t_vec	orig;
	t_vec	light_sum;

	if (depth <= 0 || !check_hittable_to_all_obj(data, ray))
		ray->color = gen_vec(0, 0, 0);
	else
	{
		set_face_front_normal(&ray->normal, ray->dir);
		orig = sum_vec(ray->orig, mul_vec(ray->ray_max, ray->dir));
		light_sum = sum_all_light(data, data->obj.l, ray, orig);
		ray->color = gen_reflection_color(ray->color, light_sum);
	}
}

static void	shoot_each_ray_to_pixel(t_data *data, t_vec pixel, int i, int j)
{
	int		di;
	int		dj;
	t_vec	dir;
	t_ray	ray;

	dir = unit_vec(sub_vec(pixel, data->obj.c.point));
	ray = gen_ray(data->obj.c.point, dir);
	ray_tracing_recur(data, &ray, DEPTH);
	if (ray.color.e[R] < 0)
		handling_error(INVAL_RES);
	else
	{
		dj = 0;
		while (dj < data->ratio)
		{
			di = 0;
			while (di < data->ratio)
			{
				put_color_pixel_to_img(&data->img, ray.color, i + di, j + dj);
				di ++;
			}
			dj ++;
		}
	}
}

void	shoot_ray_to_pixel(t_data *data)
{
	int		i;
	int		j;
	int		ratio;
	t_vec	tmp_pixel;
	t_vec	pixel;

	ratio = data->ratio;
	j = 0;
	while (j < data->img_h)
	{
		i = 0;
		while (i < data->img_w)
		{
			tmp_pixel = sum_vec(mul_vec(i, data->vp.w_unit_vec), \
								mul_vec(j, data->vp.h_unit_vec));
			pixel = sum_vec(data->vp.upper_left_pixel, tmp_pixel);
			shoot_each_ray_to_pixel(data, pixel, i * ratio, j * ratio);
			i ++;
		}
		j ++;
	}
}
