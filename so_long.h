/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:36:42 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 14:21:32 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

typedef struct info {
	void	*mlx;
	void	*win;
	int		map_height;
	int		map_width;
	char	**map;
}	t_data;

typedef struct x_y {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	xe;
	int	ye;
	int	xc;
	int	yc;
	int	xp;
	int	yp;
}	t_x_y;

typedef struct cord {
	int	x;
	int	y;
}	t_coord;

typedef struct pics{
	void	*w;
	void	*b;
	void	*e;
	void	*p;
	void	*c;
}	t_assets;

char	*get_next_line(int fd);
int		get_width(char **map);
int		get_height(char **map);
size_t	ft_strlen(const char *s);
int		check_map(char **map);
char	**get_map(int fd);
void	draw_map(t_data data);
t_coord	get_coord(t_data *data);
int		get_items(t_data data);
int		move(int keycode, t_data *data);
void	*ft_memset(void *b, int c, size_t len);

#endif