# **************************************************************************** #
                                                                             #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 15:01:56 by tsomchan          #+#    #+#              #
#    Updated: 2023/09/19 15:01:58 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a

INC		=	get_next_line.h
INC_B	=	get_next_line_bonus.h

SRC 	=	get_next_line.c get_next_line_utils.c
SRC_B	=	$(SRC:.c=_bonus.c)

OBJ_PTH	=	obj/
OBJ		=	$(SRC:%.c=$(OBJ_PTH)%.o)
OBJ_B	=	$(SRC_B:%.c=$(OBJ_PTH)%.o)

AR		=	ar rc
CC		=	cc -g
CFLAGS	=	-Wall -Wextra -Werror
B_SIZE	:=	42
CFLAGS_BUFF	=	-D BUFFER_SIZE=$(B_SIZE)
RM		=	rm -f

all : $(NAME)

ifdef b
B_SIZE = $(b)
endif

$(NAME): $(OBJ) 
	$(AR) $@ $^

$(OBJ_PTH)%.o: %.c $(INC) $(INC_B) | $(OBJ_PTH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PTH):
	mkdir -p $(OBJ_PTH)
	@echo "$(D_GREEN)compiled $@$(NC)"

clean:
	$(RM) $(addprefix $(OBJ_PTH), $(OBJ)) #$(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_B)
	$(AR) $(NAME) $(addprefix $(OBJ_PTH), $^)

.PHONY = all clean fclean re bonus

#	my additional rules
clear:
	clear

NORM	= $(SRC) $(INC) $(SRC_B) $(INC_B)

norm: clear
	norminette --version
	norminette $(NORM)

log: clear
	git log --name-status -2

clean_more:
	rm -f $(NAME)
	rm -f .DS_Store
	rm -f main.a

.PHONY += clear norm log clean_more

#	git
push:
	git push
	clear && git log --name-status -1

git_add:
	git add .
ifdef m
	git commit -m "$(m)"
endif

git: git_add push

.PHONY += push git_add git

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

#	testers
#USER_PTH	=	/Users/tsomchan/
#PROJECT_PTH	=	$(USER_PTH)github/get_next_line/
#TESTER_PTH	=	$(USER_PTH)testers/
#GNL			=	$(PROJECT_PTH)gnlTester/

#gnl:
#ifdef v
#	make $(v) -C $(GNL)
#else
#	make -C $(GNL)
#endif

#testers: gnl

#.PHONY += gnl testers

#	my testing rules
#T_PTH		=	testing/
#MYFT		=	$(addprefix $(T_PTH), coloring.c cosmetic.c result_compare.c \
#			result_output.c result_text.c)
#MYFT_INC	= 	myft.h
#T_HEADER	=	$(SRC) $(MYFT)
#T_HEADER_B	=	$(SRC_B) $(MYFT)
#T_SRC		=	testing/main.c $(T_HEADER)
#T_SRC_B	=	testing/main_b.c $(T_HEADER_B)
#T_NAME		=	main.a
#T_NAME_B	=	main_b.a

#test:
#	$(CC) $(CFLAGS_BUFF) $(T_SRC) -o $(T_NAME)
#	clear
#	norminette $(v).c
#	./$(T_NAME)

#test_b:
#	$(CC) $(CFLAGS_BUFF) $(T_SRC_B) -o $(T_NAME_B)
#	./$(T_NAME_B)

#val:
#	$(CC) $(CFLAGS_BUFF) $(T_SRC) -o $(T_NAME)
#	clear
#	valgrind ./$(T_NAME)
##	norminette $(NORM)

#.PHONY += test test_b val 
