/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:38 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/31 23:56:13 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_all(char *all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		if (all[i] == '\n')
		{
			i++;
			if (all[i] && all[i] == '\n'
				&& all[i +1] != '\n' && all[i + 1] != '\0')
				return (0);
		}
		else
			i++;
	}
	return (1);
}

char	**get_map(int fd)
{
	char	*tmp;
	char	*all;
	char	**map;

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
	if (!check_all(all))
	{
		free (all);
		return (NULL);
	}
	map = ft_split(all, '\n');
	free (all);
	return (map);
}
