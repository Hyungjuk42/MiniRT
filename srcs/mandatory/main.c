/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:12 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 19:55:13 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/mlx_utils.h"
#include "../../includes/mandatory/append_object.h"

void	handling_error(int flag)
{
	if (flag == WRONG_ARG)
		printf("Error: wrong arguments\n");
	else if (flag == OPEN_FILE)
		printf("Error: can not open file\n");
	else if (flag == WRONG_FORM)
		printf("Error: wrong format\n");
	else if (flag == NOT_A_NUM)
		printf("Error: not a number\n");
	else if (flag == NO_CAMERA)
		printf("Error: there's no camera\n");
	else if (flag == SIZE_MATCH)
		printf("Error: size doesn't match\n");
	else if (flag == OUT_OF_BND)
		printf("Error: range out of bound\n");
	else if (flag == INVAL_RES)
		printf("Error: invalid result!\n");
	else if (flag == NORM_FAIL)
		printf("Error: normalization failed!\n");
	exit (1);
}

void	set_data_init(t_data *data)
{
	data->mouse_x = INT32_MAX;
	data->mouse_y = INT32_MAX;
	set_img_size(data);
	data->total_w = data->img_w * RATIO;
	data->total_h = data->img_h * RATIO;
	data->ratio = RATIO;
	set_viewport(&data->vp, data);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	open_rt_file(ac, av, &fd);
	parse_rt_file(&data, fd);
	set_camera_origin(&data, &data.obj);
	set_data_init(&data);
	set_mlx_img(&data, &data.img);
	shoot_ray_to_pixel(&data);
	print_mlx_img(&data, &data.img);
	exit(0);
}
