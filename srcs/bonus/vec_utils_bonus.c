/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:32 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 20:19:44 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/bonus/vec_bonus.h"
#include <time.h>
#include <stdlib.h>

t_vec	trim_max_light(t_vec light)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (light.e[i] > 1)
			light.e[i] = 1;
		i ++;
	}
	return (light);
}

t_vec	gen_reflection_color(t_vec surface_color, t_vec light)
{
	light = trim_max_light(light);
	light.e[0] = surface_color.e[0] * light.e[0];
	light.e[1] = surface_color.e[1] * light.e[1];
	light.e[2] = surface_color.e[2] * light.e[2];
	return (light);
}

void	set_face_front_normal(t_vec *normal, t_vec dir)
{
	if (dot_vec(*normal, dir) > 0)
		*normal = mul_vec(-1, *normal);
}

void	print_vec(t_vec vec)
{
	printf("x:[%.2lf] y:[%.2lf] z:[%.2lf]\n", vec.e[0], vec.e[1], vec.e[2]);
}

t_vec	gen_rand_dir(t_vec normal)
{
	t_vec	ret;
	int		i;

	srand((unsigned int)time(NULL));
	i = 0;
	while (i < 3)
	{
		ret.e[i] = (double)rand() / RAND_MAX - 0.5;
		i++;
	}
	return (sum_vec(unit_vec(ret), normal));
}
