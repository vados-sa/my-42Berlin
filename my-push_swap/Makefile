NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
LIBFT		= libft.a
LIBFTDIR	= ./libft

# SRCS
SRCS	= main.c stack_utils.c error_manage.c swap.c push.c reverse_rotate.c\
			rotate.c algorithms.c algorithm_utils.c init_a_for_pb.c\
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