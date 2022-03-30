/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 03:24:42 by sgamraou          #+#    #+#             */
/*   Updated: 2021/11/30 03:17:55 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}
