# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 19:16:18 by mofikrat          #+#    #+#              #
#    Updated: 2019/04/19 18:02:34 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################
# NAME ########################################
###############################################

NAME = libft.a

###############################################
# HEADERS TO INCLUDE
###############################################

HEADERS = libft.h

###############################################
# SOURCES #####################################
###############################################

SRC_PATH = .

SRC_NAME =	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_strdup.c			\
			ft_strcpy.c			\
			ft_strncpy.c		\
			ft_strcat.c			\
			ft_strncat.c		\
			ft_strlcat.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_strnstr.c		\
			ft_strcmp.c			\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_memalloc.c		\
			ft_memdel.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_isws1.c			\
			ft_isws2.c			\
			ft_countws1.c		\
			ft_countws2.c		\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_isws1.c			\
			ft_isws2.c			\
			ft_countws1.c		\
			ft_countws2.c		\
			ft_nwords2c.c		\
			ft_strlen2c.c		\
			ft_ndigits.c		\
			ft_abs.c			\
			ft_swapbits.c		\
			ft_reversebits.c	\
			ft_printbits.c		\
			ft_sign.c			\
			ft_printhex.c		\
			ft_ispower2.c		\
			ft_iseven.c			\
			ft_strrev.c			\
			ft_swap.c			\
			ft_sortinttab.c		\

###############################################
# OBJECTS #####################################
###############################################

OBJ_PATH = .

OBJ_NAME = $(SRC_NAME:.c=.o)

###############################################
# COMPILATION VARIABLES #######################
###############################################

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

###############################################
# ALIASES + FLAGS #############################
###############################################

CFLAGS = -Wall -Werror -Wextra

#CC = gcc $(CFLAGS)
CC = gcc

#NRFLAGS = -R CheckForbiddenSourceHeader

###############################################
# ECHO COLORS #################################
###############################################

C1 = \033[1;32m # LIGHT GREEN
C2 = \033[0;32m # GREEN
C3 = \033[0;31m # RED
C4 = \033[1;34m # BLUE
BC1 = \033[41m # RED BACKGROUND
NC = \033[0m # NO COLOR DELIMITER

###############################################
###############################################
# RULES #######################################
###############################################
all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n${C2}        \\---------\\    | M |       ${NC}"
	@echo "${C2}        /  __    __\\   | O |       ${NC}"
	@echo "${C2}       /_/# \\__/# \\    | F |      ${NC}"
	@echo "${C2}    (.   \\__/  \\__/    | I |      ${NC}"
	@echo "${C2}      )       _,  |    | K |       ${NC}"
	@echo "${C2} _____/\\     _   /     | R |      ${NC}"
	@echo "${C2}     \\  \._____,/      | A |      ${NC}"
	@echo "${C2}     ..__)\\  /(_\      | T |      ${NC}"
	@echo "${C2}        \\) \\/  ( \                     ${NC}"
	@echo "${C2}           |   42 \\\ ${BC1} LIBFT by mofikrat ᒡ◯ᵔ◯ᒢ$ ${NC}"
	@	@echo "\n$(C4)# CREATING LIBFT ... ################################# ${NC}"
	@echo "$(C4)######################################################\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(C2)[OK]$(NC) $(C1) $(NAME) CREATED SUCCESSFULLY !!! $(NC)\n"

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

norminette:
	norminette $(SRC) $(HEADERS)

clean:
	@echo "\n${C2}        \\---------\\    | M |       ${NC}"
	@echo "${C2}        /  __    __\\   | O |       ${NC}"
	@echo "${C2}       /_/# \\__/# \\    | F |      ${NC}"
	@echo "${C2}    (.   \\__/  \\__/    | I |      ${NC}"
	@echo "${C2}      )       _,  |    | K |       ${NC}"
	@echo "${C2} _____/\\     _   /     | R |      ${NC}"
	@echo "${C2}     \\  \._____,/      | A |      ${NC}"
	@echo "${C2}     ..__)\\  /(_\      | T |      ${NC}"
	@echo "${C2}        \\) \\/  ( \                     ${NC}"
	@echo "${C2}           |   42 \\\ ${BC1} LIBFT by mofikrat ᒡ◯ᵔ◯ᒢ$ ${NC}"
	@echo "\n$(C4)# CLEANING OBJECT FILES from $(NAME) ROOT FOLDER ... # ${NC}"
	@echo "$(C4)######################################################\n"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(C2)[OK]$(NC) $(C1)OBJECT FILES REMOVED SUCCESSFULLY !!! $(NC)\n"

fclean: clean
	@echo "$(C4)# REMOVING $(NAME) from PROJECT FOLDER ... ########### $(NC)"
	@echo "$(C4)######################################################\n"
	@rm -f $(NAME)
	@echo "$(C2)[OK]$(NC) $(C1)PROJECT FOLDER CLEANED SUCCESSFULLY !!! $(NC)\n"

re: fclean all

.PHONY: all, clean, fclean, re, norminette
