# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edalexan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 23:40:46 by edalexan          #+#    #+#              #
#    Updated: 2024/08/26 08:25:23 by edalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

CC      = cc

SRCS    = ./srcs/so_finally_end.c ./srcs/so_graphics_3.c ./srcs/so_graphics_extras_2.c ./srcs/so_logic_2.c ./srcs/so_long.c ./srcs/so_verifications_3.c ./srcs/so_graphics_2.c ./srcs/so_graphics.c ./srcs/so_graphics_extras.c ./srcs/so_logic.c ./srcs/so_verifications_2.c ./srcs/so_verifications.c

OBJS    = $(SRCS:.c=.o)

CFLAGS  = -Wall -Wextra -Werror

COMP_LFT = cd ./utils/libft && make

COMP_MLX = cd ./minilibx-linux && make

LIBFT   = -L./utils/libft -lft

MLX     = -L./minilibx-linux -lmlx -lXext -lX11

MAKEFLAGS += -s

all:    $(NAME)

$(NAME): $(OBJS)
	$(COMP_LFT)
	$(COMP_MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)
	@echo "\033[32msuccessfully\033[0m!!"

val:    all
	valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map.ber

%.o: ./srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "objs out!"

fclean: clean
	cd ./utils/libft && make fclean
	cd ./minilibx-linux && make clean
	rm -f $(NAME)

re:    fclean all

.PHONY: all clean fclean re val

