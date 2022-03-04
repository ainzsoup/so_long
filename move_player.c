/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:21:21 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 18:49:36 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, t_coord cord, int c, void *sussy, void *map_bg)
{
	if (data->map[cord.y - 1][cord.x] == '0' || data->map[cord.y -1][cord.x] == 'C' || (data->map[cord.y - 1][cord.x] == 'E' && c == 0))
		{	
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx, data->win, sussy, 75 * cord.x, 75 * (cord.y - 1));
			mlx_put_image_to_window(data->mlx, data->win, map_bg, 75 * cord.x, 75 * cord.y); 
			if (data->map[cord.y - 1][cord.x] == 'E')
			{
				data->map[cord.y][cord.x] = '0';
				data->map[cord.y - 1][cord.x] = 'P';
				mlx_destroy_window(data->mlx, data->win);
				printf ("you won !\n");
				exit (0);		
			}
			data->map[cord.y][cord.x] = '0';
			data->map[cord.y - 1][cord.x] = 'P';
			cord.y--;
		}
}

int move(int keycode, t_data *data)
{
	static int	count = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	t_x_y res;
	void *sussy = mlx_xpm_file_to_image(data->mlx, "P.xpm", &res.xp, &res.yp);
	void *map_bg = mlx_xpm_file_to_image(data->mlx, "0.xpm", &res.x0, &res.y0);
	void *wall = mlx_xpm_file_to_image(data->mlx, "W.xpm", &res.x1, &res.y1);
	t_coord cord = get_coord(data);
	int c = get_items(*data);
	
	
	if (keycode == 13)
	{
		move_up(data, cord, c, sussy, map_bg);		
		count += 1;
		printf("%d moves.\n", count);
		
	}
	if (keycode == 1)
	{
		if (data->map[cord.y + 1][cord.x] == '0' || data->map[cord.y + 1][cord.x] == 'C' || (data->map[cord.y + 1][cord.x] == 'E' && c == 0))
		{
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx, data->win, sussy, 75 * cord.x, 75 * (cord.y + 1));
			mlx_put_image_to_window(data->mlx, data->win, map_bg, 75 * cord.x, 75 * cord.y);
			if (data->map[cord.y + 1][cord.x] == 'E')
			{
				data->map[cord.y][cord.x] = '0';
				data->map[cord.y + 1][cord.x] = 'P';
				mlx_destroy_window(data->mlx, data->win);
				printf ("you won !\n");
				exit (0);		
			}
			data->map[cord.y][cord.x] = '0';
			data->map[cord.y + 1][cord.x] = 'P';
			cord.y++;
			count += 1;
			printf("%d moves.\n", count);
		}
	}
	if (keycode == 0)
	{
		if (data->map[cord.y][cord.x - 1] == '0' || data->map[cord.y][cord.x - 1] == 'C' || (data->map[cord.y][cord.x - 1] == 'E' && c == 0))
		{
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx, data->win, sussy, 75 * (cord.x - 1), 75 * cord.y);
			mlx_put_image_to_window(data->mlx, data->win, map_bg, 75 * cord.x, 75 * cord.y);
			if (data->map[cord.y][cord.x - 1] == 'E')
			{
				data->map[cord.y][cord.x] = '0';
				data->map[cord.y - 1][cord.x] = 'P';
				mlx_destroy_window(data->mlx, data->win);
				printf ("you won !\n");
				exit (0);		
			}
			data->map[cord.y][cord.x] = '0';
			data->map[cord.y][cord.x - 1] = 'P';
			cord.x--;
			count += 1;
			printf("%d moves.\n", count);
		}
	}
	if (keycode == 2)
	{
		if (data->map[cord.y][cord.x + 1] == '0' || data->map[cord.y][cord.x + 1] == 'C' || (data->map[cord.y][cord.x + 1] == 'E' && c == 0))
		{
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx, data->win, sussy, 75 * (cord.x + 1), 75 * cord.y);
			mlx_put_image_to_window(data->mlx, data->win, map_bg, 75 * cord.x, 75 * cord.y);
			if (data->map[cord.y][cord.x + 1] == 'E')
			{
				data->map[cord.y][cord.x] = '0';
				data->map[cord.y][cord.x + 1] = 'P';
				mlx_destroy_window(data->mlx, data->win);
				printf ("you won !\n");
				exit (0);		
			}
			data->map[cord.y][cord.x] = '0';
			data->map[cord.y][cord.x + 1] = 'P';
			cord.x++;
			count += 1;
			printf("%d moves.\n", count);

		}
	}
return 0;
}
