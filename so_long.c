/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/10 21:58:15 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frames(t_data d, t_files f, int i, int j)
{
	static int	frame;

	if (frame == 0)
	{
		mlx_put_image_to_window(d.mlx, d.win, f.t, 75 * j, 75 * i);
		frame++;
	}
	else if (frame == 1)
	{
		mlx_put_image_to_window(d.mlx, d.win, f.r, 75 * j, 75 * i);
		frame = 0;
	}
}

int	animate(t_data *d)
{
	t_files	f;
	int		j;
	int		i;
	static int delay;

	if (delay == 5000)
	{	
		init(&f, d);
		i = 0;
		while (d->m[i])
		{
			j = 0;
			while (d->m[i][j])
			{
				if (d->m[i][j] == 'X')
					frames(*d, f, i, j);
				j++;
			}
			i++;
		}
		delay = 0;
	}
	else
		delay++;
	return (1);
}

int	main(void)
{
	int		fd;
	t_data	d;

	fd = open ("map.ber", O_RDONLY);
	d.m = get_map(fd);
	if (!check_map(d.m))
	{
		printf("Invalid map bro try another one.\n");
		exit(0);
	}
	d.mlx = mlx_init();
	d.h = get_height(d.m);
	d.w = get_width(d.m);
	d.win = mlx_new_window(d.mlx, d.w * 75, d.h * 75, "so_long");
	draw_map(d);
	mlx_loop_hook(d.mlx, animate, &d);
	mlx_key_hook(d.win, game, &d);
	mlx_loop(d.mlx);
}
