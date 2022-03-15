/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:38 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/15 04:37:13 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd)
{
	char	*tmp;
	char	*all;
	char	**map;

	tmp = ft_strdup("");
	all = ft_strdup("");
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp)
			all = ft_strjoin(all, tmp);
	}
	free (tmp);
	map = ft_split(all, '\n');
	free (all);
	return (map);
}
