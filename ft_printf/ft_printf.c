/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:26:25 by sgamraou          #+#    #+#             */
/*   Updated: 2021/11/30 17:06:14 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_format(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		len += ft_putpointer(va_arg(args, unsigned long));
	else if (*format == 'd' || *format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += ft_putchar(*format);
		else if (*format == '%')
		{
			format++;
			if (*format == '%')
				len += ft_putchar('%');
			else
				len += what_format(format, args);
		}
		format++;
	}
	va_end(args);
	return (len);
}
