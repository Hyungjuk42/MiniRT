/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_object.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:34:29 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/23 17:34:53 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPEND_OBJECT_H
# define APPEND_OBJECT_H

# include "miniRT.h"

typedef struct s_data	t_data;

double	set_double_range(char *str, int min, int max);
t_vec	set_vec_range(char *str, int min, int max);
t_vec	set_color(char *str);
void	set_light(t_data *data, char **str_set, int idx);
void	set_ambient_light(t_data *data, char **str_set, int idx);
void	set_camera(t_data *data, char **str_set, int idx);
void	set_sphere(t_data *data, char **str_set, int idx);
void	set_plane(t_data *data, char **str_set, int idx);
void	set_cylinder(t_data *data, char **str_set, int idx);
void	set_hyperboloid(t_data *data, char **str_set, int idx);

#endif
