/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:28:06 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:38:08 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/mlx_utils_bonus.h"

static void	move_and_render(int keycode, t_data *data)
{
	if (keycode == 0)
		data->obj.c.point.e[0] -= 0.3;
	else if (keycode == 1)
		data->obj.c.point.e[2] += 0.3;
	else if (keycode == 2)
		data->obj.c.point.e[0] += 0.3;
	else if (keycode == 13)
		data->obj.c.point.e[2] -= 0.3;
	else if (keycode == 15)
	{
		data->img_w = data->total_w;
		data->img_h = data->total_h;
		data->ratio = 1;
		set_viewport(&data->vp, data);
	}
}

static void	change_obj_material(int keycode, t_data *data)
{
	int	*page_num;
	int	*c_obj;

	page_num = &data->obj.cur_mat_page;
	if (keycode >= 18 && keycode <= 21)
	{
		c_obj = (int *)ft_lstfind(data->obj.obj, *page_num + keycode - 18);
		if (c_obj)
			*c_obj = (*c_obj + 1) % MAT_MAX;
	}
	else if (keycode == 27)
	{
		*page_num -= 4;
		if (*page_num < 0)
			*page_num = ((data->obj.obj_total - 1) / 4) * 4;
	}
	else if (keycode == 24)
	{
		*page_num += 4;
		if (data->obj.obj_total <= *page_num)
			*page_num = 0;
	}
}

static void	visible_ptr(t_data *data)
{
	data->mouse_invisible = (data->mouse_invisible + 1) % 2;
	if (data->mouse_invisible)
		mlx_mouse_hide();
	else
		mlx_mouse_show();
}

int	keyboard_handling(int keycode, t_data *data)
{
	move_and_render(keycode, data);
	change_obj_material(keycode, data);
	if (keycode == 8)
		data->cur_l_val = (data->cur_l_val + 1) % 3;
	if ((keycode >= 0 && keycode < 3) || (keycode >= 18 && keycode <= 21) || \
		(keycode == 8) || (keycode == 13) || (keycode == 15) || \
		(keycode == 24) || (keycode == 27))
		make_new_image(data, &data->mlx, &data->img);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	if (keycode == 15)
	{
		set_data_init(data, data->light_val[0]);
		set_viewport(&data->vp, data);
	}
	if (keycode == 9)
		visible_ptr(data);
	return (0);
}

int	mouse_handling(int x, int y, t_data *data)
{
	double	x_rad;
	double	y_rad;
	t_vec	ret;

	if (data->mouse_x == INT32_MAX || data->mouse_y == INT32_MAX)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		return (0);
	}
	x_rad = ((double)(data->mouse_x - x)) / 180 * M_PI;
	y_rad = ((double)(data->mouse_y - y)) / 180 * M_PI;
	if (data->mouse_invisible)
		mlx_mouse_move(data->mlx.win, data->mouse_x, data->mouse_y);
	else
	{
		data->mouse_x = x;
		data->mouse_y = y;
	}
	ret = gen_vec(-sin(x_rad), sin(y_rad), -(cos(x_rad) + cos(y_rad)));
	data->obj.c.view = ret;
	data->obj.c.up = gen_vec(0, 1, 0);
	make_new_image(data, &data->mlx, &data->img);
	return (0);
}
