/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:24:44 by sgamraou          #+#    #+#             */
/*   Updated: 2021/11/30 03:18:22 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	static int	len;

	len = 0;
	if (nb > 9)
		ft_putunsigned(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}
