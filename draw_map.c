/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:33 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 13:56:43 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data d, int i, int j)
{
	if (d.m[j][i] == '1')
		mlx_put_image_to_window(d.mlx, d.win, d.p.w, 75 * i, 75 * j);
	else if (d.m[j][i] == 'P')
		mlx_put_image_to_window(d.mlx, d.win, d.p.pl, 75 * i, 75 * j);
	else if (d.m[j][i] == 'E')
		mlx_put_image_to_window(d.mlx, d.win, d.p.e, 75 * i, 75 * j);
	else if (d.m[j][i] == 'C')
		mlx_put_image_to_window(d.mlx, d.win, d.p.i, 75 * i, 75 * j);
	else if (d.m[j][i] == '0')
		mlx_put_image_to_window(d.mlx, d.win, d.p.b, 75 * i, 75 * j);
	else
		mlx_put_image_to_window(d.mlx, d.win, d.p.t1, 75 * i, 75 * j);
}

void	draw_map(t_data dt)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (dt.m[j])
	{
		while (dt.m[j][i])
		{
			put_image(dt, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	int k = animate(&dt); 
}
