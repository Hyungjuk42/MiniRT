/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:03 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 22:01:37 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"

void	iter_set(t_vec *dist, t_vec *vec, t_vec *orig, t_mat *mat)
{
	if (dist)
	{
		*dist = sub_vec(*dist, *orig);
		*dist = cross_mat2vec(mat, *dist);
	}
	if (vec)
	{
		*vec = cross_mat2vec(mat, *vec);
	}
}

static void	set_obj_to_basis(t_list *node, t_vec *orig, t_mat *basis)
{
	t_vec	*vec;
	t_vec	*dist;

	if (node->obj == SPHERE)
		iter_set(&((t_sp *)node->content)->center, NULL, orig, basis);
	else if (node->obj == PLANE)
	{
		dist = &((t_pl *)node->content)->point;
		vec = &((t_pl *)node->content)->normal;
		iter_set(dist, vec, orig, basis);
	}
	else if (node->obj == CYLINDER)
	{
		dist = &((t_cy *)node->content)->center;
		vec = &((t_cy *)node->content)->normal;
		iter_set(dist, vec, orig, basis);
	}
	else if (node->obj == HYPERBOLD)
	{
		dist = &((t_hb *)node->content)->center;
		vec = &((t_hb *)node->content)->normal;
		iter_set(dist, vec, orig, basis);
		gen_lin_trans_mat((t_hb *)node->content);
	}
}

static void	set_default_camera_and_light(t_data *data, t_obj *obj, t_vec *orig)
{
	t_list	*node;
	t_vec	z_base;
	t_mat	*on_basis;
	t_vec	*dist;

	node = obj->l;
	on_basis = &data->obj.c.on_basis;
	z_base = mul_vec(-1, data->obj.c.view);
	gen_on_basis(on_basis, data->obj.c.up, z_base);
	while (node != NULL)
	{
		dist = &((t_l *)node->content)->point;
		iter_set(dist, NULL, orig, &obj->c.on_basis);
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
		set_obj_to_basis(node, orig, &obj->c.on_basis);
		node = node->next;
	}
	obj->c.point = gen_vec(0, 0, 0);
	gen_diagonal_mat(&obj->c.on_basis, gen_vec(1, 1, 1));
	obj->c.view = gen_vec(0, 0, -1);
}
