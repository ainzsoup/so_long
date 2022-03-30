/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:24:25 by sgamraou          #+#    #+#             */
/*   Updated: 2021/11/30 03:17:05 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhex(unsigned long n, char *cap)
{	
	static int	len;

	len = 0;
	if (n > 15)
		ft_putlhex(n / 16, cap);
	len += ft_putchar(cap[n % 16]);
	return (len);
}

int	ft_putpointer(unsigned long p)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putlhex(p, "0123456789abcdef");
	return (len);
}
