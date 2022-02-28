/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:33 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/28 14:42:09 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data data)
{
	x_y res;
	void *wall = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/wall.xpm", &res.x1, &res.y1);
	void *map_bg = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/floor.xpm", &res.x0, &res.y0);
	void *exit = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/exit.xpm", &res.xe, &res.ye);
	void *sussy = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/sussy.xpm", &res.xp, &res.yp);
	void *item = mlx_xpm_file_to_image(data.mlx_ptr, "./pics/item.xpm", &res.xc, &res.yc);
	int i = 0;
	int j = 0;
	while (data.map[j])
	{
		while (data.map[j][i])
		{
			if (data.map[j][i] == '1')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, wall, 75 * i, 75 * j);
			else if (data.map[j][i] == 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, sussy, 75 * i, 75 * j);
			else if (data.map[j][i] == 'E')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, exit, 75 * i, 75 * j);
			else if (data.map[j][i] == 'C')
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, item, 75 * i, 75 * j);
			else 
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, map_bg, 75 * i, 75 * j);
			i++;
		}
		i = 0;
		j++;
	}
}