# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 19:01:31 by vados-sa          #+#    #+#              #
#    Updated: 2024/03/12 12:18:14 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
SERVER_SRC	= server.c
CLIENT_SRC	= client.c

# Object files
SERVER_OBJ	= $(SERVER_SRC:.c=.o)
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

# Executables
SERVER = server
CLIENT = client

all: libft ft_printf $(SERVER) $(CLIENT)

# Compiling libft and ft_printf
libft:
	@$(MAKE) -C $(LIBFT)

ft_printf:
	@$(MAKE) -C $(FT_PRINTF)

# Building server and client executables
$(SERVER): $(SERVER_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB)

$(CLIENT): $(CLIENT_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB)

# Cleanup
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf