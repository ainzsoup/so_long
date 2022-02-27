/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:36:42 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/27 02:22:38 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>


char *get_next_line(int fd);
int get_width(int x);
// size_t	ft_strlen(const char *s);
int	get_height(int y);
int	check_map(char **map);


// typedef struct s_image {
// 	void	*img;
// 	char	*path;
// 	int		img_height;
// 	int		img_width;
// }	t_image;

// typedef struct s_data {
// 	void	*ptr;
// 	void	*win;
// } t_data;


#endif