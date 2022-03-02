/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:21:04 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 14:21:16 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)b;
	while (len > 0)
	{
		ret[i] = c;
		len--;
		i++;
	}
	return (b);
}
