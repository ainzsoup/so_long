/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/27 11:56:26 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	n_of_moves(t_data *d)
{
	char	*items;	

	mlx_put_image_to_window(d->mlx, d->win, d->p.n, 0, 0);
	items = ft_itoa(d->count + 1);
	mlx_string_put(d->mlx, d->win, 160, 25, 0xffffff, items);
	free (items);
}

int	ft_error(char *msg)
{
	ft_printf(msg);
	return (1);
}

void	maperror(void)
{
	printf("Error\nInvalid map bro try another one.\n");
	exit(1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	d;

	if (ac != 2)
		return (ft_error("Error\nUsage : ./so_long_bonus + file.ber"));
	fd = open (av[1], O_RDONLY);
	d.m = get_map(fd);
	if (!(check_map(d.m) && right_extention(av[1])))
		maperror();
	system("afplay ./sus.mp3 &");
	d.count = 0;
	d.over = 0;
	d.trap_count = count_traps(d);
	d.traps = inittraps(d.trap_count);
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
