# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mofikrat <mofikrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:34:34 by mofikrat          #+#    #+#              #
#    Updated: 2020/02/22 16:34:47 by mofikrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror

SRC_DIR		= ./sources/
OBJ_DIR		= ./objects/
INC_DIR		= ./includes/

LIB_DIR		= ./libft/
LIBFT 		= $(LIB_DIR)libft.a
LIB_INC		= $(LIB_DIR)includes/
MLX_PATH	= -L /usr/local/lib/ -lmlx -lpthread -framework OpenGL -framework AppKit

CR			= "\r"$(CLEAR)
CLEAR       = "\\033[0K"
EOC			= "\033[0;0m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
PURPLEBG = "\033[0;45m"
GRAY = "\033[0;37m"
BASENAME	= `basename $(PWD)`

C1 = \033[1;32m # LIGHT GREEN
C2 = \033[0;32m # GREEN
C3 = \033[0;31m # RED
C4 = \033[1;34m # BLUE
C5 = \033[35m # PURPLE
BC5 = \033[45m # BACKGROUND PURPLE
NC = \033[0m # NO COLOR DELIMITER


SRC 		=	color.c \
				fractals.c \
				fractol.c \
				input_keyboard1.c \
				input_keyboard2.c \
				input_mouse.c \
				loop.c \
				menu_data.c \
				menu_info.c \
				reset.c \
				usage.c \
				utils.c \

OBJ 		= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -lft -L $(LIB_DIR) $(MLX_PATH) -o $(NAME)
	@echo $(CR)$(PURPLEBG)"✓✓✓ $(NAME) binary created successfully ✓✓✓"$(EOC)

	@echo "\n${C1}        \\---------\\          ${NC}"
	@echo "${C1}        /  __    __\\         ${NC}"
	@echo "${C1}       /_/# \\__/# \\         ${NC}"
	@echo "${C1}    (.   \\__/  \\__/         ${NC}"
	@echo "${C1}      )       _,  |        ${NC}"
	@echo "${C1} _____/\\     _   /          ${NC}"
	@echo "${C1}     \\  \._____,/           ${NC}"
	@echo "${C1}     ..__)\\  /(_\           ${NC}"
	@echo "${C1}        \\) \\/  ( \                     ${NC}"
	@echo "${C1}           |      \\\ ${NC}"
	@echo $(CR)$(PURPLEBG)"+++++++ $(NAME) by mofikrat +++++++"$(EOC)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(INC_DIR)fractol.h
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_INC)
	@echo $(CR)$(GRAY)  \\t + $@$(EOC)


$(LIBFT):
	@make -C $(LIB_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@echo $(CR)$(RED)"✗✗✗ FRACTOL object files were removed successfully ✗✗✗"$(EOC)
fclean: clean
	@rm -f $(NAME)
	@@make fclean -C $(LIB_DIR)
	@echo $(CR)$(RED)"✗✗✗ FRACTOL binary was removed successfully ✗✗✗"$(EOC)

	@echo "\n${C1}        \\---------\\          ${NC}"
	@echo "${C1}        /  __    __\\         ${NC}"
	@echo "${C1}       /_/# \\__/# \\         ${NC}"
	@echo "${C1}    (.   \\__/  \\__/         ${NC}"
	@echo "${C1}      )       _,  |        ${NC}"
	@echo "${C1} _____/\\     _   /          ${NC}"
	@echo "${C1}     \\  \._____,/           ${NC}"
	@echo "${C1}     ..__)\\  /(_\           ${NC}"
	@echo "${C1}        \\) \\/  ( \                     ${NC}"
	@echo "${C1}           |      \\\ ${NC}"
	@echo $(CR)$(PURPLEBG)"+++++++ THANK YOU! COME BACK SOON! +++++++"$(EOC)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re