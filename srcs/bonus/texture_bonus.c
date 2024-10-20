/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:29 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/23 20:32:35 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/mlx_utils_bonus.h"

void	checker_board(t_vec coord, t_ray *ray, t_vec color)
{
	int	x;
	int	y;

	x = floor(coord.e[0] * N_FACTOR);
	y = floor(coord.e[1] * N_FACTOR * 2);
	if ((x + y) % 2)
		ray->color = sub_vec(gen_vec(1, 1, 1), color);
	else
		ray->color = color;
}

void	normal_map(t_bump *bump, t_vec coord, t_ray *ray)
{
	t_vec			map_n;
	unsigned int	color;
	int				idx[2];

	idx[0] = (int)(coord.e[0] * (bump->img_size[1] - 1));
	idx[1] = (int)(coord.e[1] * (bump->img_size[0] - 1));
	if (idx[0] < 0 || idx[0] >= bump->img_size[1] || \
		idx[1] < 0 || idx[1] >= bump->img_size[0])
	{
		idx[0] = 0;
		idx[1] = 0;
	}
	get_tangents(ray, ray->basis[2]);
	map_n = get_normal(&bump->bump, bump->bump_size, coord);
	ray->basis[Z] = sum_vec(mul_vec(map_n.e[0], ray->basis[X]), \
				sum_vec(mul_vec(map_n.e[1], ray->basis[Y]), \
				mul_vec(map_n.e[2], ray->basis[2])));
	color = get_img_color(&bump->img, idx[0], idx[1]);
	ray->color = gen_vec(color >> 16 & 0xFF, color >> 8 & 0xFF, color & 0xFF);
	ray->color = div_vec(255, ray->color);
}
