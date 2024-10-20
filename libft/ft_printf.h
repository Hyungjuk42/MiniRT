/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:42:00 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:23:00 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int	print_format(const char format, int *i, va_list *ap);
int	f_char(char c, int *i);
int	f_string(char *s, int *i);
int	f_pointer(void *s, int *i);
int	f_decimal(int d, int *i);
int	f_uphex(unsigned int n, int *i);
int	f_lowhex(unsigned int n, int *i);
int	f_uint(unsigned int d, int *i);
int	f_percent(int *i);
int	ft_printf(const char *format, ...);
int	rec_print(long long n, int *i, char *base);
int	p_rec_print(unsigned long n, int *i, char *base);
int	err_va_end(va_list *ap);

#endif