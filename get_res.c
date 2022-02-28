/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:10 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/28 06:55:27 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_width(char **map)
{
	return (ft_strlen(map[0]) - 1);
}

int get_height(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}

// int main()
// {
// 	printf ("%d \n", get_height(50));
// 	return (0);
// }