/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:36:42 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/28 06:22:02 by sgamraou         ###   ########.fr       */
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

typedef struct info {
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_height;
	int		map_width;
	char 	**map;
}	t_data;

typedef struct x_y {
	int x0;
	int y0;
	int x1;
	int y1;
	int xe;
	int ye;
	int xc;
	int yc;
	int xp;
	int yp;
}	x_y;

char *get_next_line(int fd);
int get_width(char **map);
int	get_height(char **map);
size_t	ft_strlen(const char *s);
int	check_map(char **map);
char **get_map(int fd);
void	draw_map(t_data data);



// typedef struct s_data {
// 	void	*ptr;
// 	void	*win;
// } t_data;


#endif