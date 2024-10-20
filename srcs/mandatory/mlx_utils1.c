/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:19 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:13 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/mlx_utils.h"

void	make_new_image(t_data *data, t_mlx_data *mlx, t_img *img)
{
	mlx_destroy_image(mlx->mlx, img->img);
	img->img = mlx_new_image(mlx->mlx, data->total_w, data->total_h);
	img->addr = mlx_get_data_addr(\
	data->img.img, &img->bits_per_pixel, &img->line_length, &img->endian);
	set_camera_origin(data, &data->obj);
	shoot_ray_to_pixel(data);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
}

int	keyboard_handling(int keycode, t_data *data)
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
	if ((keycode >= 0 && keycode < 3) || (keycode == 13) || (keycode == 15))
		make_new_image(data, &data->mlx, &data->img);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		exit(0);
	}
	if (keycode == 15)
		set_data_init(data);
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
	else if (abs(data->mouse_x - x) < 3 && abs(data->mouse_y - y) < 3)
	{
		return (0);
	}
	x_rad = ((double)(data->mouse_x - x)) / 180 * M_PI;
	y_rad = ((double)(data->mouse_y - y)) / 180 * M_PI;
	data->mouse_x = x;
	data->mouse_y = y;
	ret = gen_vec(-sin(x_rad), sin(y_rad), -(cos(x_rad) + cos(y_rad)));
	data->obj.c.view = ret;
	data->obj.c.up = gen_vec(0, 1, 0);
	make_new_image(data, &data->mlx, &data->img);
	return (0);
}

void	set_mlx_img(t_data *data, t_img *img)
{
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(\
	data->mlx.mlx, data->total_w, data->total_h, "miniRT");
	img->img = mlx_new_image(data->mlx.mlx, data->total_w, data->total_h);
	img->addr = mlx_get_data_addr(\
	data->img.img, &img->bits_per_pixel, &img->line_length, &img->endian);
}
