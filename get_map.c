/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:38 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/11 03:44:48 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (!line[0] || line[0] == '\n')
			break ;
		free (line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**store_map(int fd, int line)
{
	int		j;
	char	**map;

	j = 0;
	map = malloc(sizeof(char *) * (line + 1));
	while (j < line)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	map[j] = 0;
	return (map);
}

char	**get_map(int fd)
{
	int	line;

	line = lines(fd);
	close (fd);
	fd = open ("map.ber", O_RDONLY);
	return (store_map(fd, line));
}
