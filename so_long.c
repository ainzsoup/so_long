/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/03 21:27:08 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(void)
{
	int 	fd;
	t_data	d;

	open ("map.ber", O_RDONLY);
	d.map = get_map(fd);
	if (!check_map(d.map))
	{
		printf("Invalid map bro try another one.\n");
		exit(0);
	}
	d.mlx = mlx_init();
	d.m_h = get_height(d.map);
	d.m_w = get_width(d.map);
	d.win = mlx_new_window(d.mlx, d.m_w * 75, d.m_h * 75, "so_long");
	draw_map(d);
	mlx_key_hook(d.win, move, &d);
	mlx_loop(d.mlx);
}
