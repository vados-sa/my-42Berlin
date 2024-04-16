NAME = philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Paths
OBJDIR = ./objects

# Soure files
SRC = main.c

# Object files
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

# Building executables
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Compilation complete. Program $(NAME) is ready to run."


# Compilation rule for object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	@$(RM) $(OBJDIR)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re