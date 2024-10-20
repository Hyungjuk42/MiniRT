/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:37:47 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/13 14:47:46 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfind(t_list *lst, int to_find)
{
	if (lst == 0)
		return (NULL);
	while (lst)
	{
		if (lst->order == to_find)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
