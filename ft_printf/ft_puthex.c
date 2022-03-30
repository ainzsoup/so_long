/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:24:36 by sgamraou          #+#    #+#             */
/*   Updated: 2021/11/30 03:16:26 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *cap)
{	
	static int	len;

	len = 0;
	if (n > 15)
		ft_puthex(n / 16, cap);
	len += ft_putchar(cap[n % 16]);
	return (len);
}
