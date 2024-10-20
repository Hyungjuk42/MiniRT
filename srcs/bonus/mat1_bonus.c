/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:50:16 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 16:51:00 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/mat_bonus.h"
#include "../../libft/libft.h"

void	set_mat_rotation_part(t_mat *mat, t_vec v1, t_vec v2, t_vec v3)
{
	int	i;

	i = 0;
	if (mat == (void *)0)
		return ;
	while (i < 3)
	{
		mat->e[0][i] = v1.e[i];
		mat->e[1][i] = v2.e[i];
		mat->e[2][i] = v3.e[i];
		i ++;
	}
}

void	gen_diagonal_mat(t_mat *res, t_vec scaler)
{
	int		i;

	i = 0;
	ft_memset(res, 0, sizeof(t_mat));
	while (i < 3)
	{
		res->e[i][i] = scaler.e[i];
		i ++;
	}
}

void	sub_mat(t_mat *lhs, t_mat *rhs, t_mat *res)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			res->e[i][j] = lhs->e[i][j] - rhs->e[i][j];
			j ++;
		}
		i ++;
	}
}

void	trans_mat2vec_arr(t_mat *rhs, t_vec res[3])
{
	res[0] = gen_vec(rhs->e[0][0], rhs->e[0][1], rhs->e[0][2]);
	res[1] = gen_vec(rhs->e[1][0], rhs->e[1][1], rhs->e[1][2]);
	res[2] = gen_vec(rhs->e[2][0], rhs->e[2][1], rhs->e[2][2]);
}