# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 06:54:17 by sgamraou          #+#    #+#              #
#    Updated: 2022/03/09 10:37:52 by sgamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -I /usr/local/include so_long.c get_next_line.c utils.c check_map.c move.c get_map.c draw_map.c game.c ft_memset.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

clean:
	rm a.out

re:	all
	./a.out
	