/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:27 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/23 17:33:35 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/mlx_utils_bonus.h"

static void	ray_tracing_recur(t_data *data, t_ray *ray, int depth);

static void	sum_all_light(t_data *data, t_list *node, t_ray *ray, int depth)
{
	t_l		*light;
	t_vec	l_sum[2];
	t_ray	new_ray;
	t_vec	orig;
	t_ray	reflect_ray;

	ft_memset(l_sum, 0, sizeof(t_vec) * 2);
	orig = sum_vec(ray->orig, mul_vec(ray->ray_max, ray->dir));
	while (node)
	{
		light = (t_l *) node->content;
		new_ray = gen_ray(orig, unit_vec(sub_vec(light->point, orig)));
		new_ray.ray_max = vec_size(sub_vec(light->point, orig));
		if (dot_vec(new_ray.dir, ray->basis[2]) > 0 && \
			!check_hittable_to_all_obj(data, &new_ray))
		{
			l_sum[0] = calc_diffuse_light(light, ray, &new_ray, l_sum[0]);
			l_sum[1] = calc_specular_light(light, ray, &new_ray, l_sum[1]);
		}
		node = node->next;
	}
	reflect_ray = gen_ray(orig, sub_vec(ray->dir, \
		mul_vec(dot_vec(ray->dir, ray->basis[2]) * 2, ray->basis[2])));
	ray_tracing_recur(data, &reflect_ray, depth - 1);
	apply_phong_model(data, ray, l_sum, reflect_ray.color);
}

static void	ray_tracing_recur(t_data *data, t_ray *ray, int depth)
{
	if (depth <= 0 || !check_hittable_to_all_obj(data, ray))
		ray->color = gen_vec(0, 0, 0);
	else
	{
		set_face_front_normal(&ray->basis[2], ray->dir);
		sum_all_light(data, data->obj.l, ray, depth);
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
	ray_tracing_recur(data, &ray, data->light_val[0]);
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

void	*shoot_ray_by_thread(void *vars)
{
	int		i;
	int		j;
	int		ratio;
	t_vec	pixel;
	t_vars	*v;

	i = 0;
	v = (t_vars *)vars;
	j = v->idx;
	ratio = v->data->ratio;
	while (i < v->data->img_w)
	{
		pixel = sum_vec(mul_vec(i, v->data->vp.w_unit_vec), \
							mul_vec(j, v->data->vp.h_unit_vec));
		pixel = sum_vec(v->data->vp.upper_left_pixel, pixel);
		shoot_each_ray_to_pixel(v->data, pixel, i * ratio, j * ratio);
		i ++;
	}
	return (0);
}

void	shoot_ray_to_pixel(t_data *data)
{
	int			j;
	t_vars		*vars;

	vars = (t_vars *)ft_calloc(data->img_h, sizeof(t_vars));
	j = 0;
	while (j < data->img_h)
	{
		vars[j].data = data;
		vars[j].idx = j;
		pthread_create(&vars[j].line, 0, shoot_ray_by_thread, &vars[j]);
		j ++;
	}
	j = 0;
	while (j < data->img_h)
	{
		pthread_join(vars[j].line, 0);
		j ++;
	}
	free(vars);
}
