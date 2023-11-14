# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 10:14:55 by vvu               #+#    #+#              #
#    Updated: 2022/12/27 13:46:16 by vvu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar_fd.c ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c ft_isdigit.c ft_strjoin.c ft_strtrim.c

HEADER = libft.h

OFILE = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc  -c $(FLAG) $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
