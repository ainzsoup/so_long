/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 04:15:03 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/11 05:27:56 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_data *d)
{
	int	x;
	int	y;

	d->path.pr = "./sprites/player_right.xpm";
	d->path.pl = "./sprites/player_left.xpm";
	d->path.w = "./sprites/wall.xpm";
	d->path.bg = "./sprites/background.xpm";
	d->path.e = "./sprites/exit.xpm";
	d->path.t1 = "./sprites/trap1.xpm";
	d->path.t2 = "./sprites/trap2.xpm";
	d->path.c = "./sprites/collectible.xpm";
	d->path.n = "./sprites/border.xpm";
	d->p.b = mlx_xpm_file_to_image(d->mlx, d->path.bg, &x, &y);
	d->p.e = mlx_xpm_file_to_image(d->mlx, d->path.e, &x, &y);
	d->p.i = mlx_xpm_file_to_image(d->mlx, d->path.c, &x, &y);
	d->p.n = mlx_xpm_file_to_image(d->mlx, d->path.n, &x, &y);
	d->p.pl = mlx_xpm_file_to_image(d->mlx, d->path.pl, &x, &y);
	d->p.pr = mlx_xpm_file_to_image(d->mlx, d->path.pr, &x, &y);
	d->p.t1 = mlx_xpm_file_to_image(d->mlx, d->path.t1, &x, &y);
	d->p.t2 = mlx_xpm_file_to_image(d->mlx, d->path.t2, &x, &y);
	d->p.w = mlx_xpm_file_to_image(d->mlx, d->path.w, &x, &y);
}
