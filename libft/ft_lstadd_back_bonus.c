/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:38:02 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/16 21:37:05 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*bck;

	if (*lst == 0)
		*lst = new;
	else
	{
		if (new == 0)
			return ;
		bck = ft_lstlast(*lst);
		bck->next = new;
	}
}
