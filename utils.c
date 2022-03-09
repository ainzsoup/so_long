/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:10 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 14:20:37 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_width(char **map)
{
	return (ft_strlen(map[0]) - 1);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_coord	get_coord(t_data *data)
{
	t_coord	cord;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				break ;
			i++;
		}
		if (data->map[j][i] == 'P')
			break ;
		i = 0;
		j++;
	}
	cord.x = i;
	cord.y = j;
	return (cord);
}

int	get_items(t_data data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
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
	return (count);
}