/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:25:01 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:11 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/vec.h"

t_vec	gen_reflection_color(t_vec surface_color, t_vec light)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (light.e[i] > 1)
			light.e[i] = 1;
		i ++;
	}
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
