/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_object1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:49:53 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/append_object_bonus.h"

double	set_double_range(char *str, int min, int max)
{
	double	ret;

	ret = ft_strtod(str);
	if (ret < min || ret > max)
	{
		printf("%lf\n", ret);
		handling_error(OUT_OF_BND);
	}
	return (ret);
}

t_vec	set_vec_range(char *str, int min, int max)
{
	int		i;
	t_vec	ret;

	i = 0;
	ret = str_to_vec(str);
	while (i < 3)
	{
		if (ret.e[i] < min || ret.e[i] > max)
		{
			printf("%lf\n", ret.e[i]);
			handling_error(OUT_OF_BND);
		}
		i ++;
	}
	return (ret);
}

t_vec	set_color(char *str)
{
	t_vec	color;

	color = div_vec(255, set_vec_range(str, 0, 255));
	return (color);
}

void	set_ambient_light(t_data *data, char **str_set, int idx)
{
	static int	ord;
	double		ratio;

	if (ord == 1)
		handling_error(WRONG_ARG);
	if (idx != 3)
		handling_error(WRONG_FORM);
	ratio = set_double_range(str_set[1], 0, 1);
	if (ratio == NAN)
		handling_error(NOT_A_NUM);
	data->obj.a.color = mul_vec(ratio, set_color(str_set[2]));
	ord ++;
}

void	set_camera(t_data *data, char **str_set, int idx)
{
	static int	ord;

	if (ord == 1)
		handling_error(WRONG_ARG);
	if (idx != 4)
		handling_error(WRONG_FORM);
	data->obj.c.point = str_to_vec(str_set[1]);
	data->obj.c.view = unit_vec(set_vec_range(str_set[2], -1, 1));
	data->obj.c.fov = set_double_range(str_set[3], 0, 180) / 360 * M_PI * 2;
	data->obj.c.up = gen_vec(0, 0, 1);
	if (data->obj.c.fov == NAN)
		handling_error(NOT_A_NUM);
	ord ++;
}
