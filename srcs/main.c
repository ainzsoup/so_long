/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/27 10:29:54 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_error(char *msg)
{
	ft_printf(msg);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	d;

	if (ac != 2)
		return (ft_error("Error\nUsage : ./so_long + file.ber\n"));
	fd = open (av[1], O_RDONLY);
	d.m = get_map(fd);
	if (!(check_map(d.m) && right_extention(av[1])))
		return (ft_error("Error\nInvalid map bro try another one.\n"));
	d.count = 0;
	d.over = 0;
	d.mlx = mlx_init();
	d.h = get_height(d.m);
	d.w = get_width(d.m);
	d.win = mlx_new_window(d.mlx, d.w * 75, d.h * 75, "so_long");
	init_sprites(&d);
	draw_map(d);
	mlx_loop_hook(d.mlx, open_door, &d);
	mlx_key_hook(d.win, game, &d);
	mlx_hook(d.win, 17, 0, destroy, &d);
	mlx_loop(d.mlx);
}
