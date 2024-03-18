CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Paths
LIBFT = ./libft
FT_PRINTF = ./ft_printf

# Libraries
LIBFT_LIB = $(LIBFT)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a


# Soure files


# Object files

# Executables

all: libft ft_printf

# Compiling libft and ft_printf
libft:
	@$(MAKE) -C $(LIBFT)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

# Building executables

# Cleanup
clean:
	$(RM) 
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
	$(RM) 
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf