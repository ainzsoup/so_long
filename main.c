/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/12 08:36:30 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	n_of_moves(t_data *d)
{
	char	*items;	

	mlx_put_image_to_window(d->mlx, d->win, d->p.n, 0, 0);
	items = ft_itoa(d->count + 1);
	mlx_string_put(d->mlx, d->win, 160, 25, 0xffffff, items);
	free (items);
}

void	frames(t_data *d, int i, int j, int index)
{

	if (d->traps[index] == 0)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.t1, 75 * j, 75 * i);
		d->traps[index] = 1;
	}
	else if (d->traps[index] == 1)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->p.t2, 75 * j, 75 * i);
		d->traps[index] = 0;
	}
}

int	animate(t_data *d)
{
	int		j;
	int		i;
	static int delay;
	int index;

	index = 0;
	if (delay == 3500)
	{	
		i = -1;
		while (d->m[++i])
		{
			j = -1;
			while (d->m[i][++j])
				if (d->m[i][j] == 'X')
					frames(d, i, j, index++);
		}
		delay = 0;
	}
	else
		delay++;
	return (1);
}

int	open_door(t_data *d)
{
	int	i;
	int	j;

	animate (d);
	i = 0;
	if (d->i == 0 && d->count != 0)
	{
		while (d->m[i])
		{
			j = 0;
			while (d->m[i][j])
			{
				if (d->m[i][j] == 'E')
					mlx_put_image_to_window(d->mlx, d->win,
					d->p.eo, 75 * j, 75 * i);
				j++;
			}
			i++;
		}
		d->i = 1;
	}
	return (1);
}

int	countTraps(t_data d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (d.m[j])
	{
		while (d.m[j][i])
		{
			if (d.m[j][i] == 'X')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

int	*inittraps(int trapcount)
{
	int	i;
	int *ret;

	i = -1;
	ret = malloc(sizeof(int) * trapcount);
	while(i++ < trapcount)
		ret[i] = (1 * (i % 2));
	return (ret);
}

int	main(void)
{
	int		fd;
	t_data	d;

	fd = open ("map.ber", O_RDONLY);
	d.m = get_map(fd);
	if (!check_map(d.m))
	{
		printf("Error\nInvalid map bro try another one.\n");
		exit(0);
	}
	d.count = 0;
	d.trapCount = countTraps(d);
	d.traps = inittraps(d.trapCount);
	d.mlx = mlx_init();
	d.h = get_height(d.m);
	d.w = get_width(d.m);
	d.win = mlx_new_window(d.mlx, d.w * 75, d.h * 75, "so_long");
	init_sprites(&d);
	draw_map(d);
	mlx_loop_hook(d.mlx, open_door, &d);
	// mlx_loop_hook(d.mlx, animate, &d);
	mlx_key_hook(d.win, game, &d);
	mlx_loop(d.mlx);
}
