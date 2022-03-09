/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:21:21 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/09 10:25:51 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct t_files{
	void	*p;
	void	*b;
	void	*w;
}	t_files;

int	move_up(t_data *d, t_coord o, int c, t_files f)
{
	if (d->m[o.y - 1][o.x] == '0' || d->m[o.y -1][o.x] == 'C'
	|| (d->m[o.y - 1][o.x] == 'E' && c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			c--;
		mlx_put_image_to_window(d->mlx, d->win, f.p, 75 * o.x, 75 * (o.y - 1));
		mlx_put_image_to_window(d->mlx, d->win, f.b, 75 * o.x, 75 * o.y);
		if (d->m[o.y - 1][o.x] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y - 1][o.x] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("you won !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y - 1][o.x] = 'P';
		o.y--;
		return (1);
	}
	return (0);
}

int	move_down(t_data *d, t_coord o, int c, t_files f)
{
	if (d->m[o.y + 1][o.x] == '0' || d->m[o.y + 1][o.x] == 'C'
	|| (d->m[o.y + 1][o.x] == 'E' && c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			c--;
		mlx_put_image_to_window(d->mlx, d->win, f.p, 75 * o.x, 75 * (o.y + 1));
		mlx_put_image_to_window(d->mlx, d->win, f.b, 75 * o.x, 75 * o.y);
		if (d->m[o.y + 1][o.x] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y + 1][o.x] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("you won !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y + 1][o.x] = 'P';
		o.y++;
		return (1);
	}
	return (0);
}

int	move_left(t_data *d, t_coord o, int c, t_files f)
{
	if (d->m[o.y][o.x - 1] == '0' || d->m[o.y][o.x - 1] == 'C'
	|| (d->m[o.y][o.x - 1] == 'E' && c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			c--;
		mlx_put_image_to_window(d->mlx, d->win, f.p, 75 * (o.x - 1), 75 * o.y);
		mlx_put_image_to_window(d->mlx, d->win, f.b, 75 * o.x, 75 * o.y);
		if (d->m[o.y][o.x - 1] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y][o.x - 1] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("you won !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x - 1] = 'P';
		o.x--;
		return (1);
	}
	return (0);
}

int	move_right(t_data *d, t_coord o, int c, t_files f)
{
	if (d->m[o.y][o.x + 1] == '0' || d->m[o.y][o.x + 1] == 'C'
	|| (d->m[o.y][o.x + 1] == 'E' && c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			c--;
		mlx_put_image_to_window(d->mlx, d->win, f.p, 75 * (o.x + 1), 75 * o.y);
		mlx_put_image_to_window(d->mlx, d->win, f.b, 75 * o.x, 75 * o.y);
		if (d->m[o.y][o.x + 1] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y][o.x + 1] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("you won !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x + 1] = 'P';
		o.x++;
		return (1);
	}
	return (0);
}

void	moves(int *count)
{
	*count += 1;
	printf("%d moves.\n", *count);
}

int	move(int keycode, t_data *data)
{
	static int	count;
	t_x_y		res;
	t_files		f;
	t_coord		co;
	int			c;

	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	f.p = mlx_xpm_file_to_image(data->mlx, "P.xpm", &res.xp, &res.yp);
	f.b = mlx_xpm_file_to_image(data->mlx, "0.xpm", &res.x0, &res.y0);
	f.w = mlx_xpm_file_to_image(data->mlx, "W.xpm", &res.x1, &res.y1);
	co = get_coord(data);
	c = get_items(*data);
	if (keycode == 13)
	{
		if (move_up(data, co, c, f))
			moves(&count);
	}
	if (keycode == 1)
	{
		if (move_down(data, co, c, f))
			moves(&count);
	}
	if (keycode == 0)
	{
		if (move_left(data, co, c, f))
			moves(&count);
	}
	if (keycode == 2)
	{
		if (move_right(data, co, c, f))
			moves(&count);
	}
	return (0);
}
