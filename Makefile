SRCS = ./srcs/main.c \
./srcs/ft_strjoin.c \
./srcs/ft_split.c \
./srcs/animation.c \
./srcs/winorlose.c \
./srcs/get_sprites.c \
./srcs/get_next_line.c \
./srcs/utils2.c \
./srcs/utils.c \
./srcs/check_map.c \
./srcs/move.c \
./srcs/get_map.c \
./srcs/draw_map.c \
./srcs/hooks.c \
./srcs/ft_memset.c

SRCS_BONUS = ./srcs_bonus/main.c \
./srcs_bonus/ft_strjoin.c \
./srcs_bonus/ft_split.c \
./srcs_bonus/ft_itoa.c \
./srcs_bonus/animation.c \
./srcs_bonus/winorlose.c \
./srcs_bonus/get_sprites.c \
./srcs_bonus/get_next_line.c \
./srcs_bonus/utils2.c \
./srcs_bonus/utils.c \
./srcs_bonus/check_map.c \
./srcs_bonus/move.c \
./srcs_bonus/get_map.c \
./srcs_bonus/draw_map.c \
./srcs_bonus/hooks.c \
./srcs_bonus/ft_memset.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall
MLX = -lmlx -framework OpenGL -framework AppKit

NAME = so_long
BONUS = so_long_bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) ./ft_printf/libftprintf.a $(OBJS) $(MLX) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) ./ft_printf/libftprintf.a $(OBJS_BONUS) $(MLX) -o $(BONUS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf so_long so_long_bonus

re: fclean all