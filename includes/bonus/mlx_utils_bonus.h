/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:26 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:54 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_BONUS_H
# define MLX_UTILS_BONUS_H

# include "../../mlx/mlx.h"
# include "miniRT_bonus.h"

void			make_new_image(t_data *data, t_mlx_data *mlx, t_img *img);
int				keyboard_handling(int keycode, t_data *data);
int				mouse_handling(int x, int y, t_data *data);
void			set_mlx_img(t_data *data, t_img *img);
void			print_mlx_img(t_data *data, t_img *img);
void			put_color_pixel_to_img(t_img *img, t_vec vec, int i, int j);
unsigned int	get_img_color(t_img *img, int i, int j);
t_vec			get_normal(t_img *img, int size[2], t_vec normalized);
void			make_xpm2image(t_data *data, char *s_set[2]);
int				on_button(int button, int x, int y, t_data *data);
void			my_mlx_print_info(t_data *data, t_mlx_data *mlx);

#endif