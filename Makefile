# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlendine <rlendine@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 19:17:18 by rlendine          #+#    #+#              #
#    Updated: 2024/09/13 12:58:33 by rlendine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -f

NAME = libftprintf.a

FILES	=	ft_printf	\
		ft_putchar	\
		ft_puthex	\
		ft_putnbr	\
		ft_putstr	\
		ft_putunsigned	\
		ft_putptr	\
		ft_itoa		\

FLAGS = -Wall -Wextra -Werror -c

CFILES = $(FILES:%=%.c)
OFILES = $(FILES:%=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.O: %.C
	$(CC) $(FLAGS) -o $@ $<

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
