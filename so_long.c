/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/09 09:05:48 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	t_data	d;

	fd = open ("map.ber", O_RDONLY);
	d.map = get_map(fd);
	if (!check_map(d.map))
	{
		printf("Invalid map bro try another one.\n");
		exit(0);
	}
	d.mlx = mlx_init();
	d.h = get_height(d.map);
	d.w = get_width(d.map);
	d.win = mlx_new_window(d.mlx, d.w * 75, d.h * 75, "so_long");
	draw_map(d);
	mlx_key_hook(d.win, move, &d);
	mlx_loop(d.mlx);
}
