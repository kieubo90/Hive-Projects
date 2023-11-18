# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 11:57:53 by vvu               #+#    #+#              #
#    Updated: 2023/11/18 11:30:12 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = libft
SRC_DIR = src

SRC_FILES = pipex.c error_free.c path_exe.c

OFILES = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Color codes
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_DIR)/libft.a
	@echo "$(YELLOW)Creating $(NAME) executable...$(RESET)"
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME) $(OFILES)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$< compiled successfully!$(RESET)"

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OFILES)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME) executable...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@echo "$(GREEN)$(NAME) executable cleaned successfully!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
