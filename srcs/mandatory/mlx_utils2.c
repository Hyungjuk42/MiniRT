/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:21 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:12 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/mlx_utils.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

void	put_color_pixel_to_img(t_img *img, t_vec vec, int i, int j)
{
	int		ir;
	int		ig;
	int		ib;
	int		color;

	ir = (int)(255.999 * vec.e[R]);
	ig = (int)(255.999 * vec.e[G]);
	ib = (int)(255.999 * vec.e[B]);
	color = (ir << 16) + (ig << 8) + (ib);
	my_mlx_pixel_put(img, i, j, color);
}

int	close_handling(void)
{
	exit(0);
}

void	print_mlx_img(t_data *data, t_img *img)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, img->img, 0, 0);
	mlx_hook(data->mlx.win, ON_KEYDOWN, 1L << 0, keyboard_handling, data);
	mlx_hook(data->mlx.win, ON_MOUSE, 0L, mouse_handling, data);
	mlx_hook(data->mlx.win, ON_DESTROY, 0L, close_handling, data);
	mlx_loop(data->mlx.mlx);
}
