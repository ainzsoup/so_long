/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:27 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/03 21:44:17 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct i_j{
	int	i;
	int	j;
}	t_index;

t_index	just_index(t_index index)
{
	index.i = 0;
	index.j = 0;
	return (index);
}

int	check_1(char **m)
{
	t_index	x;
	int		ascii[255];

	ft_memset(ascii, 0, sizeof(ascii));
	x = just_index(x);
	while (m[x.i])
	{
		x.j = 0;
		while (m[x.i][x.j])
		{
			if (m[x.i][x.j] == 'C' || m[x.i][x.j] == 'E' || m[x.i][x.j] == 'P')
			{
				ascii[(unsigned char)m[x.i][x.j]] += 1;
			}
			if (m[x.i][x.j] != '0' && m[x.i][x.j] != '1' && m[x.i][x.j] != 'C'
			&& m[x.i][x.j] != 'E' && m[x.i][x.j] != 'P' && m[x.i][x.j] != '\n')
				return (0);
			x.j++;
		}
		x.i++;
	}
	if (ascii[(unsigned char) 'E'] != 1 || ascii[(unsigned char) 'P'] != 1
		|| ascii[(unsigned char) 'C'] == 0)
		return (0);
	return (1);
}

int	check_2(char **m)
{
	t_index	x;

	x = just_index(x);
	while (m[x.i])
	{
		x.j = 0;
		if (x.i == 0 || !m[x.i + 1])
		{
			while (m[x.i][x.j])
			{
				if (m[x.i][x.j] != '1' && m[x.i][x.j] != '\n')
					return (0);
				x.j++;
			}
		}
		else
		{	
			while (m[x.i][x.j])
			{
				if (m[x.i][0] != '1' || m[x.i][ft_strlen(m[x.i]) - 2] != '1')
					return (0);
				x.j++;
			}
		}
		x.i++;
	}
	return (1);
}

// int	check_25(char **m)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (m[i] != )
// 	{
// 		while (m[i][j])
// 		{
// 			if (m[i][0] != '1' || m[i][ft_strlen(m[i]) - 2] != '1')
// 				return (0);
// 		j++;
// 		}
// 		i++;
// 	}
// }

int	check_3(char **map)
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
	if (check_1(map) && check_2(map) && check_3(map) && map)
		return (1);
	return (0);
}
