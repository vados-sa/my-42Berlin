# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:36:44 by vados-sa          #+#    #+#              #
#    Updated: 2023/12/16 23:19:22 by vanessasant      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
NAME	= libftprintf.a
SRCS	= ft_printf.c print_char.c print_str.c print_sign_dec_int.c ft_strlen.c
			ft_putnbr_base.c print_unsign_dec_int.c ft_putnbr_base_unsign.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re