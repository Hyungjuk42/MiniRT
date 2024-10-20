/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:58:33 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:58:35 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/mlx_utils_bonus.h"

void	set_mlx_img(t_data *data, t_img *img)
{
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(\
	data->mlx.mlx, data->total_w, data->total_h, "miniRT");
	img->img = mlx_new_image(data->mlx.mlx, data->total_w, data->total_h);
	img->addr = mlx_get_data_addr(\
	data->img.img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int	on_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		if (data->cur_l_val == 0 && data->light_val[0] < 10)
			data->light_val[0]++;
		else if (data->cur_l_val == 1 && data->light_val[1] < 95)
			data->light_val[1] += 5;
		else if (data->cur_l_val == 2 && data->obj.c.fov <= (35.0 / 36) * M_PI)
			data->obj.c.fov += ((double)1 / 36) * M_PI;
	}
	else if (button == 5)
	{
		if (data->cur_l_val == 0 && data->light_val[0] > 1)
			data->light_val[0]--;
		else if (data->cur_l_val == 1 && data->light_val[1] > 5)
			data->light_val[1] -= 5;
		else if (data->cur_l_val == 2 && data->obj.c.fov >= (1.0 / 36) * M_PI)
			data->obj.c.fov -= ((double)1 / 36) * M_PI;
	}
	set_viewport(&data->vp, data);
	make_new_image(data, &data->mlx, &data->img);
	return (0);
}

void	my_mlx_print_info(t_data *data, t_mlx_data *mlx)
{
	sprintf(data->print_arr, "Depth: %d", data->light_val[0]);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, -1, data->print_arr);
	sprintf(data->print_arr, "Reflect Ratio: 0.%02d", data->light_val[1]);
	mlx_string_put(mlx->mlx, mlx->win, 10, 20, -1, data->print_arr);
	sprintf(data->print_arr, "FOV angle: %f", (data->obj.c.fov / M_PI) * 180);
	mlx_string_put(mlx->mlx, mlx->win, 10, 30, -1, data->print_arr);
	if (data->cur_l_val == 0)
		sprintf(data->print_arr, "Selected Value: Depth");
	else if (data->cur_l_val == 1)
		sprintf(data->print_arr, "Selected Value: Reflect Ratio");
	else if (data->cur_l_val == 2)
		sprintf(data->print_arr, "Selected Value: FOV angle");
	mlx_string_put(mlx->mlx, mlx->win, 10, 40, -1, data->print_arr);
	sprintf(data->print_arr, "Obj page: %d page", data->obj.cur_mat_page / 4);
	mlx_string_put(mlx->mlx, mlx->win, 10, 50, -1, data->print_arr);
}

void	make_new_image(t_data *data, t_mlx_data *mlx, t_img *img)
{
	mlx_destroy_image(mlx->mlx, img->img);
	img->img = mlx_new_image(mlx->mlx, data->total_w, data->total_h);
	img->addr = mlx_get_data_addr(\
	data->img.img, &img->bits_per_pixel, &img->line_length, &img->endian);
	set_camera_origin(data, &data->obj);
	shoot_ray_to_pixel(data);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	my_mlx_print_info(data, mlx);
}
