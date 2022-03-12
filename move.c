/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:34:11 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/12 12:06:13 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	over(t_data d)
{
	int	i;
	int	j;
	
	i = 0;
	while (d.m[i])
	{
		j = 0;
		while (d.m[i][j])
		{
			mlx_put_image_to_window(d.mlx, d.win, d.p.dk, 75 * j, 75 * i);
			j++;
		}
		i++;
	}
	if (d.over == 1)
		{
			mlx_put_image_to_window(d.mlx, d.win, d.p.ud, (75 * d.w) / 2 - 150, (75 * d.h) / 2 - 150);
			system("P=$(pgrep afplay /Users/sgamraou/Desktop/sussy.mp3) && kill -9 $P");
			system("afplay /Users/sgamraou/Desktop/defeat.mp3 &");
		}
	else if (d.over == 2)
		{
			mlx_put_image_to_window(d.mlx, d.win, d.p.nd, (75 * d.w) / 2 - 150, (75 * d.h) / 2 - 150);
			system("P=$(pgrep afplay /Users/sgamraou/Desktop/sussy.mp3) && kill -9 $P");
			system("afplay /Users/sgamraou/Desktop/win.mp3 &");
		}
	// system("P=$(pgrep afplay /Users/sgamraou/Desktop/sussy.mp3) && kill -9 $P");
}

void	ft_win(t_data *data)
{
	data->over = 2;
	printf("You won gg.\n");
}

void	ft_lose(t_data *data)
{
	data->over = 1;
	printf("GAME OVER\n");
}

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
		if (d->m[o.y - 1][o.x] == 'E')
			ft_win(d);
		else if (d->m[o.y - 1][o.x] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y - 1][o.x] = 'P';
		o.y--;
		(d->count) += 1;
		printf("%d moves.\n", d->count);
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
		if (d->m[o.y + 1][o.x] == 'E')
			ft_win(d);
		else if (d->m[o.y + 1][o.x] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y + 1][o.x] = 'P';
		o.y++;
		d->count += 1;
		printf("%d moves.\n", d->count);
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
		if (d->m[o.y][o.x - 1] == 'E')
			ft_win(d);
		else if (d->m[o.y][o.x - 1] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x - 1] = 'P';
		o.x--;
		d->count += 1;
		printf("%d moves.\n", d->count);
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
		if (d->m[o.y][o.x + 1] == 'E')
			ft_win(d);
		else if (d->m[o.y][o.x + 1] == 'X')
			ft_lose(d);
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x + 1] = 'P';
		o.x++;
		d->count += 1;
		printf("%d moves.\n", d->count);
	}
}
