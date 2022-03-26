/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 04:46:56 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/26 02:55:23 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_door(t_data *d)
{
	int	i;
	int	j;

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
