/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:38 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/20 19:34:59 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_map(int fd)
{
	char	*tmp;
	char	*all;
	char	**map;
	int		yo;

	yo = 0;
	tmp = ft_strdup("");
	all = ft_strdup("");
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			all = ft_strjoin(all, tmp);
	}
	free (tmp);
	map = ft_split(all, '\n');
	if (!map)
	{
		free (map);
		return (NULL);
	}
	free (all);
	return (map);
}
