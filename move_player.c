/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:21:21 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/09 09:19:01 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
typedef struct t_files{
	void	*sussy;
	void	*map_bg;
	void	*wall;
}	t_files;


int move(int keycode, t_data *data)
{
	t_files		files;
	static int	count;
	t_x_y		res;
	t_files		f;
	t_coord		cord;
	int			c; 
	if (keycode == 53)
			{
				mlx_destroy_window(data->mlx, data->win);
				exit(0);
			}
	f.sussy = mlx_xpm_file_to_image(data->mlx, "P.xpm", &res.xp, &res.yp);
	f.map_bg = mlx_xpm_file_to_image(data->mlx, "0.xpm", &res.x0, &res.y0);
	f.wall = mlx_xpm_file_to_image(data->mlx, "W.xpm", &res.x1, &res.y1);
	cord = get_coord(data);
	c = get_items(*data);
	if (keycode == 13)
	{
		if (data->map[cord.y - 1][cord.x] == '0' || data->map[cord.y -1][cord.x] == 'C' || (data->map[cord.y - 1][cord.x] == 'E' && c == 0))
		{	
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx, data->win, f.sussy, 75 * cord.x, 75 * (cord.y - 1));
			mlx_put_image_to_window(data->mlx, data->win, f.map_bg, 75 * cord.x, 75 * cord.y); 
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
			count += 1;
			printf("%d moves.\n", count);
		}
	}
	if (keycode == 1)
	{
		if (data->map[cord.y + 1][cord.x] == '0' || data->map[cord.y + 1][cord.x] == 'C' || (data->map[cord.y + 1][cord.x] == 'E' && c == 0))
		{
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx, data->win, f.sussy, 75 * cord.x, 75 * (cord.y + 1));
			mlx_put_image_to_window(data->mlx, data->win, f.map_bg, 75 * cord.x, 75 * cord.y);
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
			mlx_put_image_to_window(data->mlx, data->win, f.sussy, 75 * (cord.x - 1), 75 * cord.y);
			mlx_put_image_to_window(data->mlx, data->win, f.map_bg, 75 * cord.x, 75 * cord.y);
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
			mlx_put_image_to_window(data->mlx, data->win, f.sussy, 75 * (cord.x + 1), 75 * cord.y);
			mlx_put_image_to_window(data->mlx, data->win, f.map_bg, 75 * cord.x, 75 * cord.y);
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
