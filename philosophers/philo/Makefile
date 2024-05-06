NAME = philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -rf

# Paths
OBJDIR = ./objects

# Soure files
SRC = main.c init.c utils.c mem_manage.c

# Object files
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

# Building executables
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32;1mCompilation complete \033[5m✓ ✓ ✓\033[0m"
	@echo "\033[35;1mProgram $(NAME) is ready to run.\033[0m"


# Compilation rule for object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	@$(RM) $(OBJDIR)
	@echo "\033[33;1mObject files removed.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31;1mExecutable removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re