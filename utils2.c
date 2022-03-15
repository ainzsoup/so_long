/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:12:02 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/15 04:49:21 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	imposter(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P'
		&& c != 'X' && c != '\n')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	*inittraps(int trapcount)
{
	int	i;
	int	*ret;

	i = -1;
	ret = malloc(sizeof(int) * trapcount);
	while (i++ < trapcount)
		ret[i] = (1 * (i % 2));
	return (ret);
}
