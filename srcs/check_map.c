/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:27 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/20 19:34:48 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_1(char **m)
{
	t_index	x;
	int		ascii[255];

	ft_memset(ascii, 0, sizeof(ascii));
	just_index(&x);
	while (m[x.i])
	{
		x.j = 0;
		while (m[x.i][x.j])
		{
			if (m[x.i][x.j] == 'C' || m[x.i][x.j] == 'E' ||
			m[x.i][x.j] == 'P' || m[x.i][x.j] == '0')
			{
				ascii[(unsigned char)m[x.i][x.j]] += 1;
			}
			if (imposter(m[x.i][x.j]))
				return (0);
			x.j++;
		}
		x.i++;
	}
	if (ascii[(unsigned char) 'E'] == 0 || ascii[(unsigned char) 'P'] != 1
		|| ascii[(unsigned char) 'C'] == 0 || ascii[(unsigned char) '0' == 0])
		return (0);
	return (1);
}

int	check_2(char **m)
{
	t_index	x;

	just_index(&x);
	while (m[x.i])
	{
		x.j = 0;
		if (x.i == 0 || !m[x.i + 1])
		{
			while (m[x.i][x.j])
			{
				if (m[x.i][x.j] != '1')
					return (0);
				x.j++;
			}
		}
		x.i++;
	}
	return (1);
}

int	check_3(char **m)
{
	int	i;
	int	j;
	int	end;

	end = ft_strlen(m[0]) - 1;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][0] != '1' || m[i][end] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_4(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char **map)
{	
	if (check_1(map) && map && check_2(map) && check_3(map) && check_4(map))
		return (1);
	return (0);
}
