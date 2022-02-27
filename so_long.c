/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/27 01:05:32 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fd = open ("map.ber", O_RDONLY);
char **map = get_map(fd);

int	main(void)
{
	int x;
	int y;
	void *ptr = mlx_init();
	void *img = mlx_xpm_file_to_image(ptr, "./pics/wall.xpm", &x, &y);
	void *win = mlx_new_window(ptr, get_width(x), get_height(y), "window");
	for (int i = 0; i <= 9; i++ )
		mlx_put_image_to_window(ptr, win, img, i*x, 0);
	mlx_loop(ptr);
}



















                                                                        