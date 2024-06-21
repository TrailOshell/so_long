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

NAME	=	so_long

INC_PTH	=	inc/
INC		=	-I$(INC_PTH)

INC_SO_LONG		=	$(INC_PTH)so_long.h

SRC_PTH	=	src/
SRC		=	main.c util.c sl_itoa.c \
			error.c free.c debug.c \
			is_conditions.c \
			get_next_row.c line.c grid.c set_map.c set_object.c flood_fill.c \
			sprites.c render.c \
			mlx_events.c input.c \

OBJ_PTH	=	obj/
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)

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

$(OBJ_PTH)%.o: $(SRC_PTH)%.c Makefile $(INC_SO_LONG)| $(OBJ_PTH)
	$(CC) $(CFLAGS) $(INC) $(GNL_INC) $(MLX_INC) -c $< -o $@
	@echo "$(D_GREEN)compiled $<$(NC)"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) -o $@ $(MLX_FLAGS)
	@echo "$(D_GREEN)compiled $@$(NC)"

$(OBJ_PTH):
	mkdir -p $(OBJ_PTH)
	@echo "$(D_GREEN)compiled $@$(NC)"

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

test =	test.ber

t: all
	./$(NAME) $(test)

clear:
	@clear

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