# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:36:44 by vados-sa          #+#    #+#              #
#    Updated: 2023/12/20 13:01:11 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
SRC		= ft_printf.c
SRC_PRINTERS = $(addprefix printers/, print_char.c\
									print_str.c\
									print_pointer.c\
									print_sign_dec_int.c\
									print_unsign_dec_int.c\
									print_hex_int_low.c\
									print_hex_int_upper.c)
SRC_AUXILIATORS = $(addprefix auxiliators/, ft_strlen.c\
									ft_putnbr_base.c\
									ft_putnbr_base_unsign.c\
									ft_putnbr_hex_base.c)

OBJS = $(SRC:.c=.o)
OBJS_PRINTERS = $(SRC_PRINTERS:.c=.o)
OBJS_AUXILIATORS = $(SRC_AUXILIATORS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS_PRINTERS) $(OBJS_AUXILIATORS)
	ar rc $(NAME) $(OBJS) $(OBJS_PRINTERS) $(OBJS_AUXILIATORS)
	
clean:
	$(RM) $(OBJS) $(OBJS_PRINTERS) $(OBJS_AUXILIATORS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re