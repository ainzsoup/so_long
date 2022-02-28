/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:52:40 by sgamraou          #+#    #+#             */
/*   Updated: 2022/02/28 06:06:39 by sgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(void)
{
	int fd = open ("map.ber", O_RDONLY);
	t_data data;
	data.map = get_map(fd);
	if (!check_map(data.map))
	{
		printf("Invalid map bro try another one.\n");
		exit(0);		
	}
	data.mlx_ptr = mlx_init();
	data.map_height = get_height(data.map);
	data.map_width = get_width(data.map);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map_width * 75, data.map_height * 75, "so_long");
	draw_map(data);
	
	// for (int i = 0; i <= ft_strlen(map[0]); i++ )
	// 	mlx_put_image_to_window(ptr, win, img, i*x, 0);
	mlx_loop(data.mlx_ptr);
}



















                                                                        