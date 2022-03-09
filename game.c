/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:21:21 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/09 11:13:42 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(int *count)
{
	*count += 1;
	printf("%d moves.\n", *count);
}

void	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	init(t_files *f, t_data *data)
{
	t_x_y	res;

	(*f).p = mlx_xpm_file_to_image(data->mlx, "P.xpm", &res.xp, &res.yp);
	(*f).b = mlx_xpm_file_to_image(data->mlx, "0.xpm", &res.x0, &res.y0);
	(*f).w = mlx_xpm_file_to_image(data->mlx, "W.xpm", &res.x1, &res.y1);
}

int	game(int keycode, t_data *data)
{
	static int	count;
	t_files		f;
	t_coord		co;

	init (&f, data);
	co = get_coord(data);
	f.c = get_items(*data);
	if (keycode == 53)
		destroy(data);
	if (keycode == 13)
	{
		if (move_up(data, co, f))
			moves(&count);
	}
	if (keycode == 1)
	{
		if (move_down(data, co, f))
			moves(&count);
	}
	if (keycode == 0)
	{
		if (move_left(data, co, f))
			moves(&count);
	}
	if (keycode == 2)
	{
		if (move_right(data, co, f))
			moves(&count);
	}
	return (0);
}
