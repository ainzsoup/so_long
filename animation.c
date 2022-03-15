/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 04:46:56 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/15 05:03:15 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frames(t_data *d, int i, int j, int index)
{
	if (d->traps[index] == 0)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.t1, 75 * j, 75 * i);
		d->traps[index] = 1;
	}
	else if (d->traps[index] == 1)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.t2, 75 * j, 75 * i);
		d->traps[index] = 0;
	}
}

int	animate(t_data *d)
{
	int			j;
	int			i;
	static int	delay;
	int			index;

	index = 0;
	if (delay == 3500)
	{	
		i = -1;
		while (d->m[++i])
		{
			j = -1;
			while (d->m[i][++j])
				if (d->m[i][j] == 'X')
					frames(d, i, j, index++);
		}
		delay = 0;
	}
	else
		delay++;
	return (1);
}

int	open_door(t_data *d)
{
	int	i;
	int	j;

	animate (d);
	i = 0;
	if (d->i == 0 && d->count != 0)
	{
		while (d->m[i])
		{
			j = 0;
			while (d->m[i][j])
			{
				if (d->m[i][j] == 'E')
					mlx_put_image_to_window(d->mlx, d->win,
						d->p.eo, 75 * j, 75 * i);
				j++;
			}
			i++;
		}
		d->i = 1;
	}
	if (d->over == 1 || d->over == 2)
		over (*d);
	return (1);
}

int	count_traps(t_data d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (d.m[j])
	{
		while (d.m[j][i])
		{
			if (d.m[j][i] == 'X')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}
