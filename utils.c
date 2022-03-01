/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:10 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/01 13:24:18 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t ft_strlen(const char *s)
{
	size_t i = 0;
	while(s[i])
		i++;
	return i;
}

int get_width(char **map)
{
	return (ft_strlen(map[0]) - 1);
}

int get_height(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

coord	get_coord(t_data *data)
{
	coord cord;
	int i = 0;
	int j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				break;
			i++;
		}
		if (data->map[j][i] == 'P')
			break;
		i = 0;
		j++;
	}
	cord.x = i;
	cord.y = j;
	return (cord);
}

int get_items(t_data data)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (data.map[j])
	{
		while (data.map[j][i])
		{
			if (data.map[j][i] == 'C')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return count;
}



