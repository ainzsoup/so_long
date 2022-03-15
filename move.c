/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:34:11 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/15 05:34:04 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *d, t_coord o)
{
	if (d->m[o.y - 1][o.x] == '0' || d->m[o.y -1][o.x] == 'C'
	|| d->m[o.y - 1][o.x] == 'X'
	|| (d->m[o.y - 1][o.x] == 'E' && d->i == 0))
	{
		n_of_moves(d);
		if (d->m[o.y][o.x] == 'C')
			d->i--;
		if (d->l_r == 1)
			mlx_put_image_to_window(d->mlx, d->win, d->p.pl,
				75 * o.x, 75 * (o.y - 1));
		else
			mlx_put_image_to_window(d->mlx, d->win, d->p.pr,
				75 * o.x, 75 * (o.y - 1));
		mlx_put_image_to_window(d->mlx, d->win, d->p.b, 75 * o.x, 75 * o.y);
		printf("%d moves.\n", d->count);
		if (d->m[o.y - 1][o.x] == 'E')
			ft_win(d);
		else if (d->m[o.y - 1][o.x] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y - 1][o.x] = 'P';
		o.y--;
		(d->count) += 1;
	}
}

void	move_down(t_data *d, t_coord o)
{
	if (d->m[o.y + 1][o.x] == '0' || d->m[o.y + 1][o.x] == 'C'
	|| d->m[o.y + 1][o.x] == 'X'
	|| (d->m[o.y + 1][o.x] == 'E' && d->i == 0))
	{	
		n_of_moves(d);
		if (d->m[o.y][o.x] == 'C')
			d->i--;
		if (d->l_r == 1)
			mlx_put_image_to_window(d->mlx, d->win, d->p.pl,
				75 * o.x, 75 * (o.y + 1));
		else
			mlx_put_image_to_window(d->mlx, d->win, d->p.pr,
				75 * o.x, 75 * (o.y + 1));
		mlx_put_image_to_window(d->mlx, d->win, d->p.b, 75 * o.x, 75 * o.y);
		printf("%d moves.\n", d->count);
		if (d->m[o.y + 1][o.x] == 'E')
			ft_win(d);
		else if (d->m[o.y + 1][o.x] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y + 1][o.x] = 'P';
		o.y++;
		d->count += 1;
	}
}

void	move_left(t_data *d, t_coord o)
{
	if (d->m[o.y][o.x - 1] == '0' || d->m[o.y][o.x - 1] == 'C'
	|| d->m[o.y][o.x - 1] == 'X'
	|| (d->m[o.y][o.x - 1] == 'E' && d->i == 0))
	{	
		n_of_moves(d);
		d->l_r = 1;
		if (d->m[o.y][o.x] == 'C')
			d->i--;
		mlx_put_image_to_window(d->mlx, d->win, d->p.pl,
			75 * (o.x - 1), 75 * o.y);
		mlx_put_image_to_window(d->mlx, d->win, d->p.b, 75 * o.x, 75 * o.y);
		printf("%d moves.\n", d->count);
		if (d->m[o.y][o.x - 1] == 'E')
			ft_win(d);
		else if (d->m[o.y][o.x - 1] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x - 1] = 'P';
		o.x--;
		d->count += 1;
	}
}

void	move_right(t_data *d, t_coord o)
{
	if (d->m[o.y][o.x + 1] == '0' || d->m[o.y][o.x + 1] == 'C'
	|| d->m[o.y][o.x + 1] == 'X'
	|| (d->m[o.y][o.x + 1] == 'E' && d->i == 0))
	{	
		n_of_moves(d);
		d->l_r = 2;
		if (d->m[o.y][o.x] == 'C')
			d->i--;
		mlx_put_image_to_window(d->mlx, d->win, d->p.pr,
			75 * (o.x + 1), 75 * o.y);
		mlx_put_image_to_window(d->mlx, d->win, d->p.b, 75 * o.x, 75 * o.y);
		printf("%d moves.\n", d->count);
		if (d->m[o.y][o.x + 1] == 'E')
			ft_win(d);
		else if (d->m[o.y][o.x + 1] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x + 1] = 'P';
		o.x++;
		d->count += 1;
	}
}
