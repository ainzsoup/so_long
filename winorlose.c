/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winorlose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 04:53:28 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/15 05:42:17 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	center(int w)
{
	int	k;

	k = (75 * w) / 2 - 150;
	return (k);
}

void	over(t_data d)
{
	int	i;
	int	j;

	i = 0;
	while (d.m[i])
	{
		j = 0;
		while (d.m[i][j])
		{
			mlx_put_image_to_window(d.mlx, d.win, d.p.dk, 75 * j, 75 * i);
			j++;
		}
		i++;
	}
	if (d.over == 1)
	{
		mlx_put_image_to_window(d.mlx, d.win, d.p.ud, center(d.w), center(d.h));
		system("P=$(pgrep afplay ./sus.mp3) && kill -9 $P");
		system("afplay ./defeat.mp3 &");
	}
	else if (d.over == 2)
	{
		mlx_put_image_to_window(d.mlx, d.win, d.p.nd, center(d.w), center(d.h));
		system("P=$(pgrep afplay ./sus.mp3) && kill -9 $P&& afplay ./win.mp3");
	}
}

void	ft_win(t_data *data)
{
	data->over = 2;
	printf("You won gg.\n");
}

void	ft_lose(t_data *data)
{
	data->over = 1;
	printf("GAME OVER\n");
}