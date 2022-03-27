/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:21:21 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/27 11:45:46 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	destroy(t_data *data)
{
	system("P=$(pgrep afplay /Users/sgamraou/Desktop/sussy.mp3) && kill -9 $P");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	game(int keycode, t_data *data)
{
	t_coord		co;

	co = get_coord(data);
	data->i = get_items(*data);
	if (keycode == 53)
		destroy(data);
	if (!data->over)
	{
		if (keycode == 13)
			move_up(data, co);
		if (keycode == 1)
			move_down(data, co);
		if (keycode == 0)
			move_left(data, co);
		if (keycode == 2)
			move_right(data, co);
	}
	return (0);
}
