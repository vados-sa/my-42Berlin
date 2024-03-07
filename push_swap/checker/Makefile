
NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Directories
LIBFT_DIR = ../push_swap/libft
PUSH_SWAP_DIR = ../push_swap

# Library Paths
LIBS = -L$(LIBFT_DIR) -lft -L$(PUSH_SWAP_DIR) -lpush_swap

SRCS	= checker.c get_next_line.c 
OBJS = $(SRCS:.c=.o)

all:	$(NAME)


$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(PUSH_SWAP_DIR) libpush_swap
	$(CC) $(CFLAGS) $(OBJS) -L$(PUSH_SWAP_DIR) -lpush_swap -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PUSH_SWAP_DIR) clean


fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PUSH_SWAP_DIR) fclean

re: fclean all

.PHONY: all clean fclean re