# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:41:13 by vvu               #+#    #+#              #
#    Updated: 2023/06/01 11:40:59 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_put_ptr.c ft_utils.c ft_put_hex.c ft_put_unsigned.c

OFILE = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(SRC)
	cc -c $(FLAG) $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
