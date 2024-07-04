# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 16:46:54 by tsomchan          #+#    #+#              #
#    Updated: 2024/06/19 22:21:48 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

INC_PTH			=	inc/
INC				=	-I$(INC_PTH)

INC_SO_LONG		=	$(INC_PTH)so_long.h

SRC_PTH			=	src/
SRC				=	main.c

SRC_UTIL_PTH	=	util/
SRC	+=	$(addprefix $(SRC_UTIL_PTH), util.c sl_itoa.c is_conditions.c)

SRC_INIT_PTH	=	init/
SRC	+=	$(addprefix $(SRC_INIT_PTH), get_next_row.c line.c grid.c \
		set_map.c check_map_input.c set_object.c flood_fill.c) \

SRC_RENDER_PTH	=	render/
SRC	+=	$(addprefix $(SRC_RENDER_PTH), sprites.c render.c)

SRC_EVENT_PTH	=	event/
SRC	+=	$(addprefix $(SRC_EVENT_PTH), mlx_events.c input.c)

SRC_PATROL_PTH	=	patrol/
SRC	+=	$(addprefix $(SRC_PATROL_PTH), patrol.c pathfinding.c)

SRC_DEBUG_PTH	=	debug/
SRC	+=	$(addprefix $(SRC_DEBUG_PTH), error.c free.c debug.c check_debug.c)

OBJ_PTH	=	obj/
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ_SUB_PTHS =	$(OBJ_PTH) $(addprefix $(OBJ_PTH),	$(SRC_UTIL_PTH) $(SRC_INIT_PTH) \
				$(SRC_PATROL_PTH) $(SRC_RENDER_PTH) $(SRC_EVENT_PTH) $(SRC_DEBUG_PTH))

BONUS_PTH	=	bonus/

# get_next_line
GNL_PTH	=	gnl/
GNL		=	$(GNL_PTH)get_next_line.a
# GNL_INC	=	$(GNL_PTH)get_next_line.h
GNL_INC	=	-I$(GNL_PTH)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g
RM		=	rm -f
RM_RF	= 	rm -rf

MLX_PTH		=	mlx
MLX			=	$(MLX_PTH)/libmlx.a
MLX_FLAGS	=	-L$(MLX_PTH) -l$(MLX_PTH) -L/usr/lib -I$(MLX_PTH) -lXext -lX11 -lm -lz
#MLX_INC		=	-I/usr/include -I$(MLX_PTH) -O3
MLX_INC		=	-I$(MLX_PTH) -O3

all: $(MLX) $(GNL) $(NAME)

$(OBJ_PTH)%.o: $(SRC_PTH)%.c Makefile $(INC_SO_LONG)| $(OBJ_SUB_PTHS)
	$(CC) $(CFLAGS) $(INC) $(GNL_INC) $(MLX_INC) -c $< -o $@
	@echo "$(D_GREEN)compiled $<$(NC)"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) -o $@ $(MLX_FLAGS)
	@echo "$(D_GREEN)compiled $@$(NC)"

#$(OBJ_PTH): 
#	mkdir -p $(OBJ_PTH)
#	@echo "$(D_GREEN)compiled $@$(NC)"

$(OBJ_SUB_PTHS):
	mkdir -p $(OBJ_PTH)
	mkdir -p $(OBJ_SUB_PTHS)

$(GNL):
	make -C ${GNL_PTH}
	@echo "$(D_GREEN)compiled $@$(NC)"

$(MLX):
	make -C ${MLX_PTH}
	@echo "$(D_GREEN)compiled $@$(NC)"

clean:
	$(RM) $(OBJ)
	$(RM_RF) $(OBJ_PTH)
	@echo "$(D_YELLOW)removed object files$(NC)"

fclean: clean
	make clean -C $(MLX_PTH)
	$(RM) $(NAME)
	@echo "$(D_YELLOW)removed $(NAME) and object files$(NC)"

re: fclean all

#	Colors
NC			=	\033[0;0m
BLACK		=	\033[0;30m
D_RED		=	\033[0;31m
D_GREEN		=	\033[0;32m
D_YELLOW	=	\033[0;33m
D_BLUE		=	\033[0;34m
D_PURPLE	=	\033[0;35m
D_CYAN		=	\033[0;36m
L_GRAY		=	\033[0;37m
D_GRAY		=	\033[1;30m
L_RED		=	\033[1;31m
L_GREEN		=	\033[1;32m
L_YELLOW	=	\033[1;33m
L_BLUE		=	\033[1;34m
L_PURPLE	=	\033[1;35m
L_CYAN		=	\033[1;36m
WHITE		=	\033[1;37m

#	my additional rules

clear:
	@clear

n: norm

norm: clear
	@norminette $(addprefix $(SRC_PTH), $(SRC)) $(SRC_S) $(SRC_C) $(BONUS_S) $(BONUS_C)
TRASH = .DS_Store

clean_more:
	$(RM_RF) $(TRASH)

#	git

git: git_add push

log: clear
	@git log --name-status -3

push:
	@git push
	-@git push intra
	-@clear && git log --name-status -1

git_add:
	@git add .
ifdef m
	@git commit -m "$(m)"
endif

.PHONY += clear norm clean_more git log push git_add

# test

h: help

help:
	@echo "$(D_PURPLE)Rules to use$(NC)"
	@echo "$(D_YELLOW)Help\t\t\t: $(NC)h help$(NC)"
	@echo "$(D_YELLOW)Norminette\t\t: $(NC)n norm$(NC)"
	@echo "$(D_YELLOW)Invalid tests\t\t: $(NC)i inv inv_file inv_size inv_line inv_layout inv_char inv_path$(NC)"
	@echo "$(D_YELLOW)Valid tests\t\t: $(NC)v val 100 200 300$(NC)"
	@echo "$(D_YELLOW)Custom Map tests\t: $(NC)m map$(NC)"
	@echo "$(D_YELLOW)\t\t\t+-> $(NC)make m m=[pth_to_map.ber]$(NC)"

MAP_PTH		=	map/
INV_MAP_PTH	=	$(MAP_PTH)invalid/
VLD_MAP_PTH	=	$(MAP_PTH)valid/

v	= 1

define	test_ber
	@echo "$(D_GREEN)Map: $(addprefix $1, $2)$(NC)"
	@-valgrind --log-file="valgrind.out" ./$(NAME) $(addprefix $1, $2)
	@-grep --color=auto -E "no leaks" valgrind.out || @-grep echo "leaks found"
	@-grep --color=auto -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:| suppressed:" valgrind.out || true
	@-grep --color=auto "ERROR SUMMARY" valgrind.out || true
	@-echo ""
endef
#	@-valgrind --log-file="valgrind.out" ./$(NAME) $(addprefix $1, $2)
#	@-grep --color=auto -E "no leaks" valgrind.out || true
#	@echo "$(D_GREEN)Map: $2$(NC)"
#	-valgrind --log-file="valgrind.out" --leak-check=full --show-leak-kinds=all ./$(NAME) $(addprefix $(INV_MAP_PTH), $1) 
#	cat valgrind.out
#	@-grep --color=auto -E "in use at exit: " valgrind.out || true
#	@-grep --color=auto -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:| suppressed:" valgrind.out || true

define	test_output_result
	@echo "$(D_GREEN)Map: $(addprefix $1, $2)$(NC)"
	@-valgrind --log-file="valgrind.out" ./$(NAME) $(addprefix $1, $2) | grep --color=auto -E "ERROR" 
	@-grep --color=auto -E "no leaks" valgrind.out || @-grep echo "leaks found"
	@-grep --color=auto -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:| suppressed:" valgrind.out || true
	@-grep --color=auto "ERROR SUMMARY" valgrind.out || true
	@-echo ""
endef

define	test_ber_full_pth
	@echo "$(D_GREEN)Map: $1 $(NC)"
	@-valgrind --log-file="valgrind.out" ./$(NAME) $1
	@-grep --color=auto -E "no leaks" valgrind.out || true
	@-grep --color=auto -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:| suppressed:" valgrind.out || true
	@-grep --color=auto "ERROR SUMMARY" valgrind.out || true
	@-echo ""
endef

# invalid map test

BER	=	.ber

$(BER):
	cp $(INV_MAP_PTH)file/.ber .ber

inv_file: all | $(BER)
	@echo "$(D_BLUE)### run test cases: invalid file$(NC)"
	-$(call test_ber, "", .ber)
	-$(call test_ber, $(INV_MAP_PTH)file/, .ber)
	-$(call test_ber, $(INV_MAP_PTH)file/, invalid_filepath.ber)
	-$(call test_ber, $(INV_MAP_PTH)file/, not_a_ber_file.sus)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_size: all
	@echo "$(D_BLUE)### run test cases: invalid size$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)size/, empty.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, not_rectangle.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 1_col.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 2_cols.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 1_line.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, 2_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_line_at_first.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_line_at_last.ber)
	-$(call test_ber, $(INV_MAP_PTH)size/, uneven_line_at_middle.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_line: all
	@echo "$(D_BLUE)### run test cases: invalid layout of lines$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)line/, empty_line.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, initial_empty_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, following_empty_lines.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, first_empty_line.ber)
	-$(call test_ber, $(INV_MAP_PTH)line/, last_empty_line.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_layout: all
	@echo "$(D_BLUE)### run test cases: invalid layout$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_top_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_bottom_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_left_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_right_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_corner_walls.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, only_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_top_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_bottom_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_left_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, no_right_walls_but_corners.ber)
	-$(call test_ber, $(INV_MAP_PTH)layout/, so_much_gaps.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_char: all
	@echo "$(D_BLUE)### run test cases: invalid character$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)char/, invalid_character.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, multiple_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, multiple_P.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, no_C.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, no_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)char/, no_P.ber)
#	-$(call test_ber, $(INV_MAP_PTH)char/, not_even_a_map.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

inv_path: all
	@echo "$(D_BLUE)### run test cases: invalid path$(NC)"
	-$(call test_ber, $(INV_MAP_PTH)path/, unreachable_C.ber)
	-$(call test_ber, $(INV_MAP_PTH)path/, unreachable_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)path/, blocked_by_E.ber)
	-$(call test_ber, $(INV_MAP_PTH)path/, blocked_by_Walls.ber)
	@echo "$(D_BLUE)# End of test cases ----- -------  ---- --- \n$(NC)"

i: inv

inv: all
	@-make --no-print-directory inv_file	
	@-make --no-print-directory inv_size
	@-make --no-print-directory inv_line
	@-make --no-print-directory inv_layout
	@-make --no-print-directory inv_char
	@-make --no-print-directory inv_path

v: val

val: all
	-$(call test_ber, $(VLD_MAP_PTH), valid_path_test.ber)

100: all
	-$(call test_ber, $(VLD_MAP_PTH), 100x6.ber)

200: all
	-$(call test_ber, $(VLD_MAP_PTH), 200x6.ber)

300: all
	-$(call test_ber, $(VLD_MAP_PTH), 300x6.ber)

p: patrol

patrol: all
	valgrind --leak-check=full ./$(NAME) $(VLD_MAP_PTH)patrol/1_patrol.ber
#	-$(call test_ber, $(VLD_MAP_PTH)patrol/, 1_patrol.ber)

m: map

map: all
ifdef m
	-$(call test_ber_full_pth, $(m))
endif