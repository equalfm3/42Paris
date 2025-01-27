# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esuslova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/28 19:18:44 by esuslova          #+#    #+#              #
#    Updated: 2019/05/01 11:42:28 by esuslova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS = fillit.h

SRC = utils.c				\
	  board.c				\
	  tetri.c				\
	  transformations.c		\
	  checkspart1.c			\
	  checkspart2.c			\
	  main.c				\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	$(CC) $(OBJ) -o $(NAME)

.%.o: .%.c
	$(CC) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re



