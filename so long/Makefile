# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 11:21:43 by vvu               #+#    #+#              #
#    Updated: 2023/06/08 17:05:22 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT_DIR = libft
GNL_DIR = get_next_line
SRC_DIR = src
PRINTF_DIR = ft_printf

SRC = main.c map.c error_map.c error_input.c error_path.c start_game.c start_game_big.c free.c control_game.c
GNL = get_next_line.c get_next_line_utils.c

SRC_OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
GNL_OBJ = $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

FLAGS = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework Appkit

CC = cc

RED =\033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRC_OBJ) $(GNL_OBJ) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	@echo "$(RED)Creating $(NAME)... $(GREEN)OK!!\n$(RESET)"
	@$(CC) $(FLAGS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(LINKS) -o $(NAME) $(SRC_OBJ) $(GNL_OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -Imlx -I$(LIBFT_DIR) -I$(GNL_DIR) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(FLAGS) -Imlx -I$(LIBFT_DIR) -I$(GNL_DIR) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR) --silent

$(PRINTF_DIR)/libftprintf.a:
	@$(MAKE) -C $(PRINTF_DIR) --silent

clean:
	@echo "$(YELLOW)Cleaning object files...$(GREEN)OK!!\n$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@$(MAKE) -C $(PRINTF_DIR) clean --silent
	@rm -f $(SRC_OBJ) $(GNL_OBJ)

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME)...$(GREEN)OK!!\n$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@$(MAKE) -C $(PRINTF_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re
