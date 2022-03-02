/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:27 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 14:22:05 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_1(char **map)
{
	int	i;
	int	j;
	int	ascii[255];

	ft_memset(ascii, 0, sizeof(ascii));
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
			{
				ascii[(unsigned char)map[i][j]] += 1;
			}
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (ascii[(unsigned char) 'E'] != 1 || ascii[(unsigned char) 'P'] != 1
		|| ascii[(unsigned char) 'C'] == 0)
		return (0);
	return (1);
}

int	check_2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j])
			{
				if (map[i][j] != '1' && map[i][j] != '\n')
					return (0);
				j++;
			}
		}
		else
			while (map[i][j])
			{
				if (map[i][0] != '1' || (!map[i][j + 1] && map[i][j - 1] != '1'))
					return (0);
				j++;
			}
		i++;
	}
	return (1);
}

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
