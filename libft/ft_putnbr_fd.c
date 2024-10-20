/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:52:45 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/14 08:12:42 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_printnbr(long long nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long long	cal;

	cal = n;
	if (cal < 0)
	{
		write(fd, "-", 1);
		cal *= -1;
	}
	if (cal == 0)
		write(fd, "0", 1);
	else
		rec_printnbr(cal, fd);
}

static void	rec_printnbr(long long nb, int fd)
{
	char	p;

	p = nb % 10 + '0';
	if (!(nb == 0))
	{
		nb /= 10;
		rec_printnbr(nb, fd);
		write(fd, &p, 1);
	}
}
