# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 19:01:31 by vados-sa          #+#    #+#              #
#    Updated: 2024/04/09 12:24:27 by vanessasant      ###   ########.fr        #
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


# Source files for main part
SERVER_SRC	= server.c
CLIENT_SRC	= client.c

# Source files for bonus part
SERVER_SRC_BONUS = server_bonus.c
CLIENT_SRC_BONUS = client_bonus.c
UTILS_SRC_BONUS = utils_bonus.c

# Object files
SERVER_OBJ	= $(SERVER_SRC:.c=.o)
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
UTILS_OBJ_BONUS = $(UTILS_SRC_BONUS:.c=.o)

# Executables
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

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

# Bonus part
bonus: libft ft_printf $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_OBJ_BONUS) $(UTILS_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_OBJ_BONUS) $(UTILS_OBJ_BONUS) $(LIBFT_LIB) $(FT_PRINTF_LIB)

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS) $(LIBFT_LIB) $(FT_PRINTF_LIB)

# Cleanup
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS) $(UTILS_OBJ_BONUS) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf bonus