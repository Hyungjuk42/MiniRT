/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:17 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 16:51:00 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/bonus/mat_bonus.h"

t_mat	cross_mat2mat(t_mat *lhs, t_mat *rhs)
{
	int		i;
	int		j;
	int		k;
	double	tmp;
	t_mat	ret;

	i = 0;
	ft_memset(&ret, 0, sizeof(t_mat));
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = -1;
			tmp = 0;
			while (++ k < 3)
				tmp += lhs->e[i][k] * rhs->e[k][j];
			ret.e[i][j] = tmp;
			j ++;
		}
		i ++;
	}
	return (ret);
}

t_vec	cross_mat2vec(t_mat *lhs, t_vec rhs)
{
	int		i;
	double	tmp;
	t_vec	ret;

	i = 0;
	while (i < 3)
	{
		tmp = 0;
		tmp += lhs->e[i][0] * rhs.e[0];
		tmp += lhs->e[i][1] * rhs.e[1];
		tmp += lhs->e[i][2] * rhs.e[2];
		ret.e[i] = tmp;
		i ++;
	}
	return (ret);
}

t_mat	transpose_mat(t_mat *rhs)
{
	int		i;
	int		j;
	t_mat	ret;

	i = 0;
	ft_memset(&ret, 0, sizeof(t_mat));
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			ret.e[j][i] = rhs->e[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}
