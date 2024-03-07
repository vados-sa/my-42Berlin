# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 13:50:06 by vados-sa          #+#    #+#              #
#    Updated: 2024/03/07 13:05:04 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

LIBFT		= libft.a
LIBFTDIR	= ./libft
LIBNAME		= libpush_swap.a # Name for the library

# Shared SRC files between push_swap and checker
SHARED_SRCS = stack_utils.c error_manage.c swap.c push.c reverse_rotate.c rotate.c
SHARED_OBJS = $(SHARED_SRCS:.c=.o)

# push_swap specific SRC files
PUSH_SWAP_SRCS = main.c algorithms.c algorithm_utils.c init_node_struct.c prep_push_utils.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)

# Combine all object files for final push_swap binary
OBJS = $(PUSH_SWAP_OBJS) $(SHARED_OBJS)

all:	$(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

# Target to create the shared library
libpush_swap: $(SHARED_OBJS)
	ar rcs $(LIBNAME) $(SHARED_OBJS)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean:	clean
	$(RM) $(NAME) $(LIBNAME)
	@make -C $(LIBFTDIR) fclean

re:	fclean all

.PHONY: all clean fclean re