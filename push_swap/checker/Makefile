
NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

LIBFT_DIR = ../push_swap/libft
LIBS = -L$(LIBFT_DIR) -lft

SRCS	= checker.c get_next_line.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)


$(NAME): $(OBJS)
		@$(MAKE) -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re push_swap