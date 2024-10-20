/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:49:57 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 22:00:58 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/miniRT_bonus.h"

void	iter_set(t_vec **list, t_mat *on_basis, t_vec *orig, t_mat *mat)
{
	t_mat	tmp;

	if (list[0])
	{
		*list[0] = sub_vec(*list[0], *orig);
		*list[0] = cross_mat2vec(mat, *list[0]);
	}
	if (list[1])
	{
		*list[1] = cross_mat2vec(mat, *list[1]);
	}
	if (on_basis)
	{
		tmp = transpose_mat(mat);
		*on_basis = cross_mat2mat(on_basis, &tmp);
	}
}

static void	set_obj_to_basis_2(t_list *node, t_vec *orig, t_mat *basis)
{
	t_vec	*list[2];
	t_mat	*on_basis;

	if (node->obj == CYLINDER)
	{
		list[0] = &((t_cy *)node->content)->center;
		list[1] = &((t_cy *)node->content)->normal;
		on_basis = &((t_cy *)node->content)->on_basis;
		iter_set(list, on_basis, orig, basis);
	}
	else if (node->obj == HYPERBOLD)
	{
		list[0] = &((t_hb *)node->content)->center;
		list[1] = &((t_hb *)node->content)->normal;
		on_basis = &((t_hb *)node->content)->on_basis;
		iter_set(list, on_basis, orig, basis);
		gen_lin_trans_mat((t_hb *)node->content);
	}
}

static void	set_obj_to_basis_1(t_list *node, t_vec *orig, t_mat *basis)
{
	t_vec	*list[2];
	t_mat	*on_basis;

	if (node->obj == SPHERE)
	{
		list[0] = &((t_sp *)node->content)->center;
		list[1] = NULL;
		on_basis = &((t_sp *)node->content)->on_basis;
		iter_set(list, on_basis, orig, basis);
	}
	else if (node->obj == PLANE)
	{
		list[0] = &((t_pl *)node->content)->point;
		list[1] = &((t_pl *)node->content)->normal;
		on_basis = &((t_pl *)node->content)->on_basis;
		iter_set(list, on_basis, orig, basis);
	}
	set_obj_to_basis_2(node, orig, basis);
}

static void	set_default_camera_and_light(t_data *data, t_obj *obj, t_vec *orig)
{
	t_list	*node;
	t_vec	z_base;
	t_mat	*on_basis;
	t_vec	*list[2];

	node = obj->l;
	on_basis = &data->obj.c.on_basis;
	z_base = mul_vec(-1, data->obj.c.view);
	gen_on_basis(on_basis, data->obj.c.up, z_base);
	while (node != NULL)
	{
		list[0] = &((t_l *)node->content)->point;
		list[1] = NULL;
		iter_set(list, NULL, orig, &obj->c.on_basis);
		node = node->next;
	}
}

void	set_camera_origin(t_data *data, t_obj *obj)
{
	t_list	*node;
	t_vec	*orig;

	node = obj->obj;
	orig = &obj->c.point;
	set_default_camera_and_light(data, obj, orig);
	while (node != NULL)
	{
		set_obj_to_basis_1(node, orig, &obj->c.on_basis);
		node = node->next;
	}
	obj->c.point = gen_vec(0, 0, 0);
	gen_diagonal_mat(&obj->c.on_basis, gen_vec(1, 1, 1));
	obj->c.view = gen_vec(0, 0, -1);
}
