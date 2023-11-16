# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 18:08:15 by vvu               #+#    #+#              #
#    Updated: 2023/05/23 09:37:17 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft
SRC_DIR = src

SRC_FILES = mv.c do_mv.c sort_advance.c index_tp.c sort_3.c pa_pb.c rra_rrb_rrr.c ra_rb_rr.c sa_sb_ss.c check_size_and_sort.c check_dup_max.c check_non_num.c check_error_sign.c ft_utils.c stack.c check_inputs.c main.c

HEADER = push_swap.h

OFILES = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

CFLAGS = -Wall -Wextra -Werror

CC = cc

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_DIR)/libft.a
	@echo "$(YELLOW)Creating $(NAME) $(RESET)"
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME) $(OFILES)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@echo "$(YELLOW)Cleaning object files... $(GREEN)OK!!\n$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@rm -f $(OFILES)

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME)....$(GREEN)OK!!\n$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re
