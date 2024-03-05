# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:36:44 by vados-sa          #+#    #+#              #
#    Updated: 2024/03/05 16:26:20 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
SRC		= ft_printf.c utils.c
SRC_PRINTERS = $(addprefix printers/, print_char.c\
									print_str.c\
									print_pointer.c\
									print_sign_dec_int.c\
									print_unsign_dec_int.c\
									print_hex_int_low.c\
									print_hex_int_upper.c)

OBJS = $(SRC:.c=.o)
OBJS_PRINTERS = $(SRC_PRINTERS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS_PRINTERS)
	ar rc $(NAME) $(OBJS) $(OBJS_PRINTERS)
	
clean:
	$(RM) $(OBJS) $(OBJS_PRINTERS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re