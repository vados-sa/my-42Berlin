# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:28:49 by vados-sa          #+#    #+#              #
#    Updated: 2024/03/18 18:03:44 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Paths
LIBFT = ./libft
FT_PRINTF = ./ft_printf
MINILIBX = ./minilibx-linux

# Libraries
LIBFT_LIB = $(LIBFT)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a
MLX_LIB = $(MINILIBX)

# Compilation flags for MinilibX and X11
MLX_FLAGS = -L$(MLX_LIB) -lmlx -lXext -lX11

# Soure files
SRC = main.c

# Object files
OBJS = $(SRC:.c=.o)

all: libft ft_printf minilibx $(NAME)

# Compiling libft and ft_printf
libft:
	@$(MAKE) -C $(LIBFT)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

minilibx:
	@$(MAKE) -C $(MINILIBX)

# Building executables
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)

# Cleanup
clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(MINILIBX) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean
	@$(MAKE) -C $(MINILIBX) clean 
                            # Usually MinilibX doesn't have an fclean rule, but calling clean as a safety

re: fclean all

.PHONY: all clean fclean re libft ft_printf minilibx