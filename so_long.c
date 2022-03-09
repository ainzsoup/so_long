/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/09 15:43:31 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame1(t_data *d, t_files f)
{
	int	i;
	int	j;

	i = 0;
	while (d->m[i])
	{
		j = 0;
		while (d->m[i][j])
		{
			if (d->m[i][j] == 'X')
				mlx_put_image_to_window(d->mlx, d->win, f.r, 75 * j, 75 * i);
			j++;
		}
		i++;
	}
}

void	frame2(t_data *d, t_files f)
{
	int	i;
	int	j;

	i = 0;
	while (d->m[i])
	{
		j = 0;
		while (d->m[i][j])
		{
			if (d->m[i][j] == 'X')
				mlx_put_image_to_window(d->mlx, d->win, f.t, 75 * j, 75 * i);
			j++;
		}
		i++;
	}
}

int	animation(t_data *d)
{
	t_files	f;

	init(&f, d);
	frame2(d, f);
	return (0);
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
	mlx_loop_hook(d.mlx, animation, &d);
	mlx_key_hook(d.win, game, &d);
	mlx_loop(d.mlx);
}
