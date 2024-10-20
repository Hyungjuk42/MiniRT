/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_object2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:49:29 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:03 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/bonus/miniRT_bonus.h"
#include "../../includes/bonus/append_object_bonus.h"

void	set_light(t_data *data, char **str_set, int idx)
{
	t_l		*l_node;
	double	ratio;

	if (idx != 4)
		handling_error(WRONG_FORM);
	l_node = (t_l *)malloc(sizeof(t_l));
	if (l_node == NULL)
		exit(1);
	l_node->point = str_to_vec(str_set[1]);
	ratio = set_double_range(str_set[2], 0, 1);
	l_node->color = mul_vec(ratio, set_color(str_set[3]));
	ft_lstadd_back(&data->obj.l, ft_lstnew(l_node, LIGHT, 0));
}

void	set_sphere(t_data *data, char **str_set, int idx)
{
	t_sp	*sp_node;
	t_list	*list_node;
	t_vec	up;

	if (idx != 6)
		handling_error(WRONG_FORM);
	sp_node = (t_sp *)malloc(sizeof(t_sp));
	if (sp_node == NULL)
		exit(1);
	sp_node->center = str_to_vec(str_set[1]);
	sp_node->rad = ft_strtod(str_set[2]) / 2;
	sp_node->color = set_color(str_set[3]);
	sp_node->matl = set_int_range(str_set[4], 0, 2);
	sp_node->bump = set_bump_map(data, str_set[5]);
	up = gen_vec(0, 0, 1);
	gen_on_basis(&sp_node->on_basis, up, up);
	if (sp_node->rad == NAN)
		handling_error(NOT_A_NUM);
	else if (sp_node->rad <= 0)
		handling_error(OUT_OF_BND);
	list_node = ft_lstnew(sp_node, SPHERE, data->obj.obj_total ++);
	ft_lstadd_back(&data->obj.obj, list_node);
}

void	set_plane(t_data *data, char **str_set, int idx)
{
	t_pl	*pl_node;
	t_list	*list_node;
	t_vec	up;

	if (idx != 6)
		handling_error(WRONG_FORM);
	pl_node = (t_pl *)malloc(sizeof(t_pl));
	if (pl_node == NULL)
		exit(1);
	pl_node->point = str_to_vec(str_set[1]);
	pl_node->normal = unit_vec(set_vec_range(str_set[2], -1, 1));
	pl_node->color = set_color(str_set[3]);
	pl_node->matl = set_int_range(str_set[4], 0, 2);
	pl_node->bump = set_bump_map(data, str_set[5]);
	up = gen_vec(0, 0, 1);
	gen_on_basis(&pl_node->on_basis, up, pl_node->normal);
	list_node = ft_lstnew(pl_node, PLANE, data->obj.obj_total ++);
	ft_lstadd_back(&data->obj.obj, list_node);
}

void	set_cylinder(t_data *data, char **str_set, int idx)
{
	t_cy	*cy_node;
	t_list	*list_node;
	t_vec	up;

	if (idx != 8)
		handling_error(WRONG_FORM);
	cy_node = (t_cy *)malloc(sizeof(t_cy));
	if (cy_node == NULL)
		exit(1);
	cy_node->center = str_to_vec(str_set[1]);
	cy_node->normal = unit_vec(set_vec_range(str_set[2], -1, 1));
	cy_node->rad = ft_strtod(str_set[3]) / 2;
	cy_node->h = ft_strtod(str_set[4]) / 2;
	cy_node->color = set_color(str_set[5]);
	cy_node->matl = set_int_range(str_set[6], 0, 2);
	cy_node->bump = set_bump_map(data, str_set[7]);
	up = gen_vec(0, 0, 1);
	gen_on_basis(&cy_node->on_basis, up, cy_node->normal);
	if (cy_node->rad == NAN || cy_node->h == NAN)
		handling_error(NOT_A_NUM);
	if (cy_node->rad <= 0 || cy_node->h <= 0)
		handling_error(OUT_OF_BND);
	list_node = ft_lstnew(cy_node, CYLINDER, data->obj.obj_total ++);
	ft_lstadd_back(&data->obj.obj, list_node);
}

void	set_hyperboloid(t_data *data, char **str_set, int idx)
{
	t_hb	*hb_node;
	t_list	*list_node;
	double	*scaler_e;

	if (idx != 8)
		handling_error(WRONG_FORM);
	hb_node = (t_hb *)malloc(sizeof(t_hb));
	if (hb_node == NULL)
		exit(1);
	hb_node->center = str_to_vec(str_set[1]);
	hb_node->normal = unit_vec(set_vec_range(str_set[2], -1, 1));
	hb_node->scaler = str_to_vec(str_set[3]);
	scaler_e = hb_node->scaler.e;
	if (scaler_e[0] <= 0 || scaler_e[1] <= 0 || scaler_e[2] <= 0)
		handling_error(OUT_OF_BND);
	hb_node->scaler.e[2] *= -1;
	hb_node->h = ft_strtod(str_set[4]) / 2;
	hb_node->color = set_color(str_set[5]);
	hb_node->matl = set_int_range(str_set[6], 0, 2);
	hb_node->bump = set_bump_map(data, str_set[7]);
	if (hb_node->h <= 0)
		handling_error(OUT_OF_BND);
	gen_on_basis(&hb_node->on_basis, gen_vec(0, 0, 1), hb_node->normal);
	list_node = ft_lstnew(hb_node, HYPERBOLD, data->obj.obj_total ++);
	ft_lstadd_back(&data->obj.obj, list_node);
}
