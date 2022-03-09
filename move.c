/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:34:11 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/09 11:52:41 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *d, t_coord o, t_files *f, int *count)
{
	if (d->m[o.y - 1][o.x] == '0' || d->m[o.y -1][o.x] == 'C'
	|| (d->m[o.y - 1][o.x] == 'E' && (*f).c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			(*f).c--;
		mlx_put_image_to_window(d->mlx, d->win, (*f).p,
			75 * o.x, 75 * (o.y - 1));
		mlx_put_image_to_window(d->mlx, d->win, (*f).b, 75 * o.x, 75 * o.y);
		if (d->m[o.y - 1][o.x] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y - 1][o.x] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("Game Over !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y - 1][o.x] = 'P';
		o.y--;
		*count += 1;
		printf("%d moves.\n", *count);
	}
}

void	move_down(t_data *d, t_coord o, t_files *f, int *count)
{
	if (d->m[o.y + 1][o.x] == '0' || d->m[o.y + 1][o.x] == 'C'
	|| (d->m[o.y + 1][o.x] == 'E' && (*f).c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			(*f).c--;
		mlx_put_image_to_window(d->mlx, d->win, (*f).p,
			75 * o.x, 75 * (o.y + 1));
		mlx_put_image_to_window(d->mlx, d->win, (*f).b, 75 * o.x, 75 * o.y);
		if (d->m[o.y + 1][o.x] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y + 1][o.x] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("Game Over !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y + 1][o.x] = 'P';
		o.y++;
		*count += 1;
		printf("%d moves.\n", *count);
	}
}

void	move_left(t_data *d, t_coord o, t_files *f, int *count)
{
	if (d->m[o.y][o.x - 1] == '0' || d->m[o.y][o.x - 1] == 'C'
	|| (d->m[o.y][o.x - 1] == 'E' && (*f).c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			(*f).c--;
		mlx_put_image_to_window(d->mlx, d->win, (*f).p,
			75 * (o.x - 1), 75 * o.y);
		mlx_put_image_to_window(d->mlx, d->win, (*f).b, 75 * o.x, 75 * o.y);
		if (d->m[o.y][o.x - 1] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y][o.x - 1] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("Game Over !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x - 1] = 'P';
		o.x--;
		*count += 1;
		printf("%d moves.\n", *count);
	}
}

void	move_right(t_data *d, t_coord o, t_files *f, int *count)
{
	if (d->m[o.y][o.x + 1] == '0' || d->m[o.y][o.x + 1] == 'C'
	|| (d->m[o.y][o.x + 1] == 'E' && (*f).c == 0))
	{	
		if (d->m[o.y][o.x] == 'C')
			(*f).c--;
		mlx_put_image_to_window(d->mlx, d->win, (*f).p,
			75 * (o.x + 1), 75 * o.y);
		mlx_put_image_to_window(d->mlx, d->win, (*f).b, 75 * o.x, 75 * o.y);
		if (d->m[o.y][o.x + 1] == 'E')
		{
			d->m[o.y][o.x] = '0';
			d->m[o.y][o.x + 1] = 'P';
			mlx_destroy_window(d->mlx, d->win);
			printf ("Game Over !\n");
			exit (0);
		}
		d->m[o.y][o.x] = '0';
		d->m[o.y][o.x + 1] = 'P';
		o.x++;
		*count += 1;
		printf("%d moves.\n", *count);
	}
}
