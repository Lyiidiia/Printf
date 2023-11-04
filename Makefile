# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcuellar <lcuellar@student42.madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 22:49:17 by lcuellar          #+#    #+#              #
#    Updated: 2023/11/04 23:08:20 by lcuellar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_itoa.c ft_printf_utils.c ft_printf.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS) -c $(SRC)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

RM = rm -f

$(NAME):
	@$(CC)
	@$(LIB) $(OBJ)
	@$(RANLIB)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
