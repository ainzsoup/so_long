/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:36:42 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/20 21:44:55 by sgamraou         ###   ########.fr       */
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

typedef struct s_traps{
	int	x;
	int	y;
}				t_traps;

typedef struct ponters{
	void	*pl;
	void	*pr;
	void	*b;
	void	*w;
	void	*t1;
	void	*t2;
	void	*n;
	void	*e;
	void	*eo;
	void	*i;
	void	*dk;
	void	*ud;
	void	*nd;
}	t_pointers;

typedef struct t_paths{
	char	*w;
	char	*pl;
	char	*pr;
	char	*e;
	char	*eo;
	char	*bg;
	char	*t1;
	char	*t2;
	char	*c;
	char	*n;
	char	*dk;
	char	*ud;
	char	*nd;
}	t_paths;

typedef struct t_files{
	void	*p;
	void	*b;
	void	*w;
	int		c;
	void	*r;
	void	*t;
	void	*n;
	void	*a;
}	t_files;

typedef struct i_j{
	int	i;
	int	j;
}	t_index;

typedef struct info {
	void		*mlx;
	void		*win;
	int			h;
	int			w;
	char		**m;
	int			l_r;
	int			count;
	int			i;
	t_files		f;
	t_paths		path;
	t_pointers	p;
	int			trap_count;
	int			*traps;
	int			over;
}	t_data;

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
	void	*t;
	void	*r;
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
int		game(int keycode, t_data *data);
void	*ft_memset(void *b, int c, size_t len);
void	just_index(t_index *index);
void	move_up(t_data *d, t_coord o);
void	move_down(t_data *d, t_coord o);
void	move_left(t_data *d, t_coord o);
void	move_right(t_data *d, t_coord o);
void	init(t_files *f, t_data *data);
int		imposter(char c);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
void	init_sprites(t_data *d);
void	n_of_moves(t_data *d);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
void	frames(t_data *d, int i, int j, int index);
int		open_door(t_data *d);
int		animate(t_data *d);
void	over(t_data d);
int		count_traps(t_data d);
int		*inittraps(int trapcount);
void	over(t_data d);
void	ft_win(t_data *data);
void	ft_lose(t_data *data);

#endif