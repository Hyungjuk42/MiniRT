/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:47:35 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:24:08 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (print_format(*format++, &i, &ap) == -1)
				return (err_va_end(&ap));
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (err_va_end(&ap));
			format++;
			i++;
		}
	}
	va_end(ap);
	return (i);
}

int	print_format(const char format, int *i, va_list *ap)
{
	if (format == 'c')
		return (f_char(va_arg(*ap, int), i));
	else if (format == 's')
		return (f_string(va_arg(*ap, char *), i));
	else if (format == 'p')
		return (f_pointer(va_arg(*ap, void *), i));
	else if (format == 'd')
		return (f_decimal(va_arg(*ap, int), i));
	else if (format == 'i')
		return (f_decimal(va_arg(*ap, int), i));
	else if (format == 'u')
		return (f_uint(va_arg(*ap, unsigned int), i));
	else if (format == 'x')
		return (f_lowhex(va_arg(*ap, unsigned long long), i));
	else if (format == 'X')
		return (f_uphex(va_arg(*ap, unsigned long long), i));
	else if (format == '%')
		return (f_percent(i));
	else
		return (f_char(format, i));
	return (0);
}

int	err_va_end(va_list *ap)
{
	va_end(*ap);
	return (-1);
}
