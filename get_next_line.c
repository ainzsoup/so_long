/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:48 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 17:49:14 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*s1;
	int		i;

	i = 0;
	while (s[i])
		i++;
	s1 = malloc(i + 1);
	i = 0;
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

char	*get_next_line(int fd)
{
	char	line[5000000];
	int		i;

	i = 0;
	ft_memset(line, 0, sizeof(line));
	while (read(fd, &line[i], 1) > 0)
		if (line[i++] == '\n')
			break ;
	if (line[0] != 0)
		return (ft_strdup(line));
	else
		return (NULL);
}
