/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 06:54:33 by sgamraou          #+#    #+#             */
/*   Updated: 2022/03/02 13:56:43 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_assets	get_files(t_data dt)
{
	t_x_y		res;
	t_assets	pics;

	pics.w = mlx_xpm_file_to_image(dt.mlx, "1.xpm", &res.x1, &res.y1);
	pics.b = mlx_xpm_file_to_image(dt.mlx, "0.xpm", &res.x0, &res.y0);
	pics.e = mlx_xpm_file_to_image(dt.mlx, "E.xpm", &res.xe, &res.ye);
	pics.p = mlx_xpm_file_to_image(dt.mlx, "P.xpm", &res.xp, &res.yp);
	pics.c = mlx_xpm_file_to_image(dt.mlx, "C.xpm", &res.xc, &res.yc);
	pics.t = mlx_xpm_file_to_image(dt.mlx, "s1.xpm", &res.xt, &res.yt);
	pics.r = mlx_xpm_file_to_image(dt.mlx, "T2.xpm", &res.xr, &res.yr);
	return (pics);
}

void	put_image(t_data dt, int i, int j, t_assets pics)
{
	if (dt.m[j][i] == '1')
		mlx_put_image_to_window(dt.mlx, dt.win, pics.w, 75 * i, 75 * j);
	else if (dt.m[j][i] == 'P')
		mlx_put_image_to_window(dt.mlx, dt.win, pics.p, 75 * i, 75 * j);
	else if (dt.m[j][i] == 'E')
		mlx_put_image_to_window(dt.mlx, dt.win, pics.e, 75 * i, 75 * j);
	else if (dt.m[j][i] == 'C')
		mlx_put_image_to_window(dt.mlx, dt.win, pics.c, 75 * i, 75 * j);
	else if (dt.m[j][i] == '0')
		mlx_put_image_to_window(dt.mlx, dt.win, pics.b, 75 * i, 75 * j);
	else
		mlx_put_image_to_window(dt.mlx, dt.win, pics.t, 75 * i, 75 * j);
}

void	draw_map(t_data dt)
{
	t_assets	pics;
	int			i;
	int			j;

	pics = get_files(dt);
	i = 0;
	j = 0;
	while (dt.m[j])
	{
		while (dt.m[j][i])
		{
			put_image(dt, i, j, pics);
			i++;
		}
		i = 0;
		j++;
	}
}
