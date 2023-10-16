# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 13:33:50 by mrodenbu          #+#    #+#              #
#    Updated: 2023/07/11 11:03:51 by mrodenbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

OBJ = $(SRC:%.c=%.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

$(OBJ):
	cc $(FLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
