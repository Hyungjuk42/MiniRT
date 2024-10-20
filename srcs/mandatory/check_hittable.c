/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:04 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:16 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/miniRT.h"

static int	itinerate_and_chk_hit(t_list *node, t_ray *ray)
{
	int	stat;

	stat = 0;
	if (node)
	{
		if (node->obj == SPHERE)
			stat = chk_hittable_sp(ray, (t_sp *)node->content);
		else if (node->obj == PLANE)
			stat = chk_hittable_pl(ray, (t_pl *)node->content);
		else if (node->obj == CYLINDER)
			stat = chk_hittable_cy(ray, (t_cy *)node->content);
		else if (node->obj == HYPERBOLD)
			stat = chk_hittable_hb(ray, (t_hb *)node->content);
		if (stat)
			ray->obj_order = node->order;
	}
	return (stat);
}

int	check_hittable_to_all_obj(t_data *data, t_ray *ray)
{
	t_list	*node;
	int		hittable;

	node = data->obj.obj;
	hittable = 0;
	while (node)
	{
		hittable |= itinerate_and_chk_hit(node, ray);
		node = node->next;
	}
	return (hittable);
}
