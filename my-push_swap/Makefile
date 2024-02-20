NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
LIBFT		= libft.a
LIBFTDIR	= ./libft

# SRCS
SRCS	= main.c init_stack.c error_manage.c

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