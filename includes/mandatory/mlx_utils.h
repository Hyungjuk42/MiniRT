/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:32 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:51 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../../mlx/mlx.h"
# include "miniRT.h"

void	make_new_image(t_data *data, t_mlx_data *mlx, t_img *img);
int		keyboard_handling(int keycode, t_data *data);
int		mouse_handling(int x, int y, t_data *data);
void	set_mlx_img(t_data *data, t_img *img);
void	print_mlx_img(t_data *data, t_img *img);
void	put_color_pixel_to_img(t_img *img, t_vec vec, int i, int j);

#endif