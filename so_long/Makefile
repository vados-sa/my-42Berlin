# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:28:49 by vados-sa          #+#    #+#              #
#    Updated: 2024/04/11 09:42:00 by vados-sa         ###   ########.fr        #
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
OBJDIR = ./objects
BONUSDIR = ./bonus

# Libraries
LIBFT_LIB = $(LIBFT)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF)/libftprintf.a
MLX_LIB = $(MINILIBX)

# Compilation flags for MinilibX and X11
MLX_FLAGS = -L$(MLX_LIB) -lmlx -lXext -lX11

# Soure files
SRC = main.c cleanup_management.c initial_check.c create_map.c parse_map.c \
		flood_fill.c init_game.c load_sprites.c render_map.c hooks.c move.c \
		free_images.c rerender.c
BONUS_SRC = $(addprefix $(BONUSDIR)/, kenemy.c load_bonus_sprites.c free_bonus.c \
		sprite_anim.c)

# Object files
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
BONUS_OBJS = $(BONUS_SRC:$(BONUSDIR)/%.c=$(OBJDIR)/%.o)

all: libft ft_printf minilibx $(NAME)

# Building executables
$(NAME): $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BONUS_OBJS) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_FLAGS)

# Compilation rule for object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -I$(MINILIBX) -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -I$(MINILIBX) -c $< -o $@

# Including external Makefiles
libft:
	@$(MAKE) -s -C $(LIBFT)

ft_printf:
	@$(MAKE) -s -C $(FT_PRINTF)

minilibx:
	@$(MAKE) -s -C $(MINILIBX)

# Cleanup
clean:
	$(RM) $(OBJDIR) $(BONUS_OBJS)
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(FT_PRINTF) clean
	@$(MAKE) -s -C $(MINILIBX) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean
	@$(MAKE) -s -C $(FT_PRINTF) fclean
	@$(MAKE) -s -C $(MINILIBX) clean 

re: fclean all

.PHONY: all clean fclean re libft ft_printf minilibx