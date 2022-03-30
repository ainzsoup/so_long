# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgamraou <sgamraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 22:36:37 by sgamraou          #+#    #+#              #
#    Updated: 2021/11/30 17:32:03 by sgamraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c ft_puthex.c ft_putnbr.c ft_putpointer.c \
ft_putstr.c ft_putunsigned.c ft_printf.c

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
