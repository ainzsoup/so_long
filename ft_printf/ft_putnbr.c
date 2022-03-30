/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:24:39 by sgamraou          #+#    #+#             */
/*   Updated: 2021/11/29 20:24:34 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				len;

	len = f_len(n);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
	return (len);
}
