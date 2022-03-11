# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 06:54:17 by sgamraou          #+#    #+#              #
#    Updated: 2022/03/11 06:17:21 by sgamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -I /usr/local/include main.c ft_itoa.c get_sprites.c get_next_line.c utils2.c utils.c check_map.c move.c get_map.c draw_map.c game.c ft_memset.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm a.out

re:	all
	./a.out
	