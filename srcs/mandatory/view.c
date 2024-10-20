/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:06 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:09 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"

void	set_img_size(t_data *data)
{
	data->img_w = WIDTH;
	data->aspect = ASPECT;
	data->img_h = data->img_w * data->aspect;
	if (data->img_h <= 0)
		data->img_h = 1;
}

void	set_viewport(t_viewport *vp, t_data *data)
{
	t_vec	upper_left;

	vp->w = 2;
	vp->h = 2 * data->aspect;
	vp->d = -(1 / tan(data->obj.c.fov / 2));
	vp->h_vec = gen_vec(0, -vp->h, 0);
	vp->w_vec = gen_vec(vp->w, 0, 0);
	vp->w_unit_vec = div_vec(data->img_w, vp->w_vec);
	vp->h_unit_vec = div_vec(data->img_h, vp->h_vec);
	upper_left = gen_vec(vp->w / 2, -vp->h / 2, -vp->d);
	vp->upper_left = sub_vec(data->obj.c.point, upper_left);
	vp->upper_left_pixel = sum_vec(vp->upper_left, \
		mul_vec(0.5, sum_vec(vp->w_unit_vec, vp->h_unit_vec)));
}
