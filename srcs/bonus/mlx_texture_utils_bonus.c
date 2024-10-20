/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_texture_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:19 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/23 20:33:29 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/mlx_utils_bonus.h"

t_vec	get_normal(t_img *img, int size[2], t_vec normalized)
{
	int				j;
	int				i;
	unsigned int	dst;
	t_vec			normal;

	i = (int)(normalized.e[0] * (size[1] - 1));
	j = (int)(normalized.e[1] * (size[0] - 1));
	if (i < 0 || i >= size[1] || j < 0 || j >= size[0])
	{
		i = 0;
		j = 0;
	}
	dst = *(unsigned int *)(img->addr + i * img->line_length + \
		j * (img->bits_per_pixel / 8));
	normal = gen_vec((dst >> 16) & 0xFF, (dst >> 8) & 0xFF, dst & 0xFF);
	normal = div_vec(255, normal);
	normal = sub_vec(mul_vec(2, normal), gen_vec(1, 1, 1));
	if (vec_size(normal) == 0)
		return (gen_vec(0, 0, 1));
	return (unit_vec(normal));
}

void	make_xpm2image(t_data *data, char *s_set[2])
{
	t_bump	*bump;
	t_img	*img;
	t_list	*bump_node;
	int		*size;

	bump = (t_bump *)ft_calloc(1, sizeof(t_bump));
	img = &bump->bump;
	size = bump->bump_size;
	img->img = mlx_xpm_file_to_image(data->mlx.mlx, s_set[0], size, size + 1);
	if (img->img == NULL)
		handling_error(WRONG_BUMP);
	img->addr = mlx_get_data_addr(img->img, \
				&img->bits_per_pixel, &img->line_length, &img->endian);
	img = &bump->img;
	size = bump->img_size;
	img->img = mlx_xpm_file_to_image(data->mlx.mlx, s_set[1], size, size + 1);
	if (img->img == NULL)
		handling_error(WRONG_BUMP);
	img->addr = mlx_get_data_addr(img->img, \
				&img->bits_per_pixel, &img->line_length, &img->endian);
	bump_node = ft_lstnew(bump, BUMP_MAP, data->bump_num ++);
	ft_lstadd_back(&data->bumpmap, bump_node);
}
