/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:26:51 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/12/06 20:37:26 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, int obj, int ord)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == 0)
		exit(1);
	ret->next = 0;
	ret->content = content;
	ret->obj = obj;
	ret->order = ord;
	return (ret);
}
