# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edalexan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 17:00:06 by edalexan          #+#    #+#              #
#    Updated: 2024/05/19 17:00:09 by edalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -silent

CFLAGS		= -Wall -Wextra -Werror -g
CC			= cc
NAME		= libft.a
FLAGLIB		= -rcs
RM			= /bin/rm -f

SRC		= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
				ft_isprint.c ft_memcmp.c ft_memset.c ft_strchr.c ft_strlcat.c\
				ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
				ft_tolower.c ft_toupper.c ft_bzero.c ft_calloc.c ft_memchr.c\
				ft_memcpy.c ft_memmove.c ft_strdup.c ft_itoa.c ft_strtrim.c\
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c\
				ft_split.c get_next_line.c ft_print_nbr_u.c ft_print_chr.c\
				ft_print_hex.c ft_print_ptr.c ft_printf.c ft_print_nbr.c\
				ft_print_str.c

OBJ			= $(SRC:.c=.o)

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c


BONUS_OBJ	= $(BONUS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) libft.h
			@echo "\033[31m1. LIBFT\033[0m"
			@echo "\033[32mCOMPILADO COM SUCESSO!! - COMPILED SUCCESSFULLY!!\n\033[0m"
			@ar $(FLAGLIB) $(NAME) $(OBJ)
			@ranlib $(NAME)

bonus:		$(BONUS_OBJ) $(NAME)
			@ar $(FLAGLIB) $(NAME) $(BONUS_OBJ)
			@ranlib $(NAME)

.c.o:
			@$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
			@echo "Files cleaned sucessfully! "
			@$(RM) $(OBJ) $(BONUS_OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
