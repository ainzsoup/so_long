/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:33 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/01 14:22:03 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

assets	get_files(t_data dt)
{
	x_y		res;
	assets	pics;

	pics.W = mlx_xpm_file_to_image(dt.mlx, "1.xpm", &res.x1, &res.y1);
	pics.B = mlx_xpm_file_to_image(dt.mlx, "0.xpm", &res.x0, &res.y0);
	pics.E = mlx_xpm_file_to_image(dt.mlx, "E.xpm", &res.xe, &res.ye);
	pics.P = mlx_xpm_file_to_image(dt.mlx, "P.xpm", &res.xp, &res.yp);
	pics.C = mlx_xpm_file_to_image(dt.mlx, "C.xpm", &res.xc, &res.yc);
	return (pics);	
} 

void	draw_map(t_data dt)
{
	assets	pics;
	int		i;
	int		j;

	pics = get_files(dt);
	i = 0;
	j = 0;
	while (dt.map[j])
	{
		while (dt.map[j][i])
		{
			if (dt.map[j][i] == '1')
				mlx_put_image_to_window(dt.mlx, dt.win, pics.W, 75 * i, 75 * j);
			else if (dt.map[j][i] == 'P')
				mlx_put_image_to_window(dt.mlx, dt.win, pics.P, 75 * i, 75 * j);
			else if (dt.map[j][i] == 'E')
				mlx_put_image_to_window(dt.mlx, dt.win, pics.E, 75 * i, 75 * j);
			else if (dt.map[j][i] == 'C')
				mlx_put_image_to_window(dt.mlx, dt.win, pics.C, 75 * i, 75 * j);
			else 
				mlx_put_image_to_window(dt.mlx, dt.win, pics.B, 75 * i, 75 * j);
			i++;
		}
		i = 0;
		j++;
	}
}
