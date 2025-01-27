# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lparis <lparis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 16:49:24 by lparis            #+#    #+#              #
#    Updated: 2021/02/23 17:21:11 by lparis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/actions_1.c \
./src/actions_2.c \
./src/actions_3.c \
./src/actions_4.c \
./src/actions_5.c \
./src/actions_6.c \
./src/editor_1.c \
./src/editor_action_area_1.c \
./src/editor_action_area_2.c \
./src/editor_action_area_3.c \
./src/editor_action_area_4.c \
./src/editor_action_area_5.c \
./src/editor_action_area_6.c \
./src/editor_action_area_7.c \
./src/editor_action_game_1.c \
./src/editor_action_group_1.c \
./src/editor_action_group_2.c \
./src/editor_action_group_3.c \
./src/editor_action_group_4.c \
./src/editor_action_group_5.c \
./src/editor_action_group_6.c \
./src/editor_action_group_7.c \
./src/editor_action_group_8.c \
./src/editor_action_paint_1.c \
./src/editor_action_paint_2.c \
./src/editor_action_player_1.c \
./src/editor_action_player_2.c \
./src/editor_action_triangle_10.c \
./src/editor_action_triangle_1.c \
./src/editor_action_triangle_2.c \
./src/editor_action_triangle_3.c \
./src/editor_action_triangle_4.c \
./src/editor_action_triangle_5.c \
./src/editor_action_triangle_6.c \
./src/editor_action_triangle_7.c \
./src/editor_action_triangle_8.c \
./src/editor_action_triangle_9.c \
./src/editor_interface_parameters_area_1.c \
./src/editor_interface_parameters_area_2.c \
./src/editor_interface_parameters_area_3.c \
./src/editor_interface_parameters_area_4.c \
./src/editor_interface_parameters_game_1.c \
./src/editor_interface_parameters_group_1.c \
./src/editor_interface_parameters_group_2.c \
./src/editor_interface_parameters_group_3.c \
./src/editor_interface_parameters_group_4.c \
./src/editor_interface_parameters_group_5.c \
./src/editor_interface_parameters_menu_1.c \
./src/editor_interface_parameters_menu_2.c \
./src/editor_interface_parameters_paint_1.c \
./src/editor_interface_parameters_paint_2.c \
./src/editor_interface_parameters_player_1.c \
./src/editor_interface_parameters_player_2.c \
./src/editor_interface_parameters_player_3.c \
./src/editor_interface_parameters_triangle_1.c \
./src/editor_interface_parameters_triangle_2.c \
./src/editor_interface_parameters_triangle_3.c \
./src/editor_interface_parameters_triangle_4.c \
./src/editor_interface_parameters_triangle_5.c \
./src/editor_interface_parameters_triangle_6.c \
./src/editor_interface_parameters_triangle_7.c \
./src/editor_interface_parameters_triangle_8.c \
./src/editor_interface_parameters_triangle_9.c \
./src/editor_menu_area_1.c \
./src/editor_menu_game_1.c \
./src/editor_menu_group_1.c \
./src/editor_menu_paint_1.c \
./src/editor_menu_player_1.c \
./src/editor_menu_triangle_1.c \
./src/engine_play_1.c \
./src/engine_play_2.c \
./src/engine_play_3.c \
./src/engine_play_4.c \
./src/engine_play_5.c \
./src/engine_play_6.c \
./src/engine_play_7.c \
./src/engine_play_8.c \
./src/engine_play_9.c \
./src/hud_1.c \
./src/hud_2.c \
./src/hud_3.c \
./src/hud_4.c \
./src/hud_5.c \
./src/hud_6.c \
./src/hud_7.c \
./src/hud_8.c \
./src/hud_9.c \
./src/initialize_10.c \
./src/initialize_1.c \
./src/initialize_2.c \
./src/initialize_3.c \
./src/initialize_4.c \
./src/initialize_5.c \
./src/initialize_6.c \
./src/initialize_7.c \
./src/initialize_8.c \
./src/initialize_9.c \
./src/input_1.c \
./src/input_2.c \
./src/input_3.c \
./src/input_4.c \
./src/input_5.c \
./src/input_6.c \
./src/input_7.c \
./src/npc_1.c \
./src/npc_2.c \
./src/tool_edit_double_1.c \
./src/tool_edit_double_2.c \
./src/tool_edit_int_1.c \
./src/tool_edit_int_2.c \
./src/tool_edit_text_1.c \
./src/tool_put_text_1.c \
./src/tool_put_texture_1.c \
./src/tools_1.c \
./src/tools_2.c \
./src/tools_3.c
CC=gcc
NAME=doom-nukem
CFLAGS=-Wall -Wextra -Werror
INC=./include/
SDL2=`sdl2-config --cflags --libs` -lm
OBJ= $(SRC:.c=.o)

.phony: all sdl2 clean fclean re

all: $(NAME)

sdl2:
	@echo user42 | sudo -S apt-get -y install libsdl2-dev
	@sudo apt -y --only-upgrade install libsdl2-dev
	@echo make: SDL2 installed.

$(NAME): sdl2 $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) -I $(INC) $(SRC) $(SDL2) 
	@echo make: Compile done.

clean:
	@$(RM) -f $(OBJ)
	@echo make: Clean done.

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all
