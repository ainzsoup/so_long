/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/28 15:10:30 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

coord	get_coord(t_data *data)
{
	coord cord;
	int i = 0;
	int j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				break;
			i++;
		}
		if (data->map[j][i] == 'P')
			break;
		i = 0;
		j++;
	}
	cord.x = i;
	cord.y = j;
	return (cord);
}

int get_items(t_data data)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (data.map[j])
	{
		while (data.map[j][i])
		{
			if (data.map[j][i] == 'C')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return count;
}

int move(int keycode, t_data *data)
{
	static int count = 0;
	if (keycode == 53)
			{
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
				exit(0);
			}
	x_y res;
	void *sussy = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/sussy.xpm", &res.xp, &res.yp);
	void *map_bg = mlx_xpm_file_to_image(data->mlx_ptr, "./pics/floor.xpm", &res.x0, &res.y0);
	coord cord = get_coord(data);
	int c = get_items(*data);
	if (keycode == 13)
	{
		if (data->map[cord.y - 1][cord.x] == '0' || data->map[cord.y -1][cord.x] == 'C' || (data->map[cord.y - 1][cord.x] == 'E' && c == 0))
		{	
			if (data->map[cord.y][cord.x] == 'C')
				c--;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sussy, 75 * cord.x, 75 * (cord.y - 1));
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map_bg, 75 * cord.x, 75 * cord.y); 
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
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sussy, 75 * cord.x, 75 * (cord.y + 1));
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map_bg, 75 * cord.x, 75 * cord.y);
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
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sussy, 75 * (cord.x - 1), 75 * cord.y);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map_bg, 75 * cord.x, 75 * cord.y);
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
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sussy, 75 * (cord.x + 1), 75 * cord.y);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, map_bg, 75 * cord.x, 75 * cord.y);
			data->map[cord.y][cord.x] = '0';
			data->map[cord.y][cord.x + 1] = 'P';
			cord.x++;
			count += 1;
			printf("%d moves.\n", count);

		}
	}
return 0;
}

int	main(void)
{
	int fd = open ("map.ber", O_RDONLY);
	t_data data;
	data.map = get_map(fd);
	if (!check_map(data.map))
	{
		printf("Invalid map bro try another one.\n");
		exit(0);
	}
	data.mlx_ptr = mlx_init();
	data.map_height = get_height(data.map);
	data.map_width = get_width(data.map);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * 75, data.map_height * 75, "so_long");
	draw_map(data);
	mlx_key_hook(data.win_ptr, move, &data);
	mlx_loop(data.mlx_ptr);
}



















                                                                        