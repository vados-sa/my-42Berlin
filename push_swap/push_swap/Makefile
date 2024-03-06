# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 13:50:06 by vados-sa          #+#    #+#              #
#    Updated: 2024/03/03 13:50:07 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
LIBFT		= libft.a
LIBFTDIR	= ./libft

# SRCS
SRCS	= main.c stack_utils.c error_manage.c swap.c push.c reverse_rotate.c\
			rotate.c algorithms.c algorithm_utils.c init_node_struct.c\
			prep_push_utils.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

# LIBFT
makelibft:
	@make -C $(LIBFTDIR)

$(NAME):	makelibft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean:	clean
	$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

re:	fclean all

.PHONY: all clean fclean re