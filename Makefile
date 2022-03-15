# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 06:54:17 by sgamraou          #+#    #+#              #
#    Updated: 2022/03/15 04:56:49 by sgamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc -I /usr/local/include main.c ft_strjoin.c ft_split.c ft_itoa.c animation.c winorlose.c get_sprites.c get_next_line.c utils2.c utils.c check_map.c move.c get_map.c draw_map.c hooks.c ft_memset.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o so_long

drip:
	cc -I /usr/local/include main.c ft_strjoin.c ft_split.c ft_itoa.c get_sprites.c get_next_line.c utils2.c utils.c check_map.c move.c get_map.c draw_map.c game.c ft_memset.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -fsanitize=address -o so_long
	
clean:
	rm so_long

re:	all
	./so_long
	