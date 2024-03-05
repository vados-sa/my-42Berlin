# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 19:01:31 by vados-sa          #+#    #+#              #
#    Updated: 2024/03/05 14:40:57 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
# Add needed libraries (libft)
#LIBFT		= libft.a
#LIBFTDIR	= path_to./libft

# Soure files
SERVER_SRC	= server.c
CLIENT_SRC	= client.c
SRC			= utils.c

# Object files
SERVER_OBJ	= $(SERVER_SRC:.c=.o)
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
OBJS		= $(SRC:.c=.o)

# Executable names
SERVER_NAME = server
CLIENT_NAME = client

all: $(SERVER_NAME) $(CLIENT_NAME)

# LIBFT
makelibft:
	@make -C $(LIBFTDIR)

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJ) $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJ) $(LIBS)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re