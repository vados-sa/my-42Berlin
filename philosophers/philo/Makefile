# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 15:22:44 by vados-sa          #+#    #+#              #
#    Updated: 2024/10/14 15:46:08 by vados-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -rf

# Paths
OBJDIR = ./objects
INCLUDES = includes

# Soure files
SRC =	sources/main.c \
		sources/init.c \
		sources/utils/utils.c \
		sources/mem_manage.c \
		sources/simulation.c \
		sources/routine_utils.c \
		sources/monitor.c

# Object files
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

# Building executables
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32;1mCompilation complete \033[5m✓ ✓ ✓\033[0m"
	@echo "\033[35;1mProgram $(NAME) is ready to run.\033[0m"


# Compilation rule for object files
$(OBJDIR)/%.o: %.c $(INCLUDES)/philo.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	@$(RM) $(OBJDIR)
	@echo "\033[37;1mObject files removed.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[37;1mExecutable removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re