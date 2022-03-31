##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for project named: map
##

SRC				=		map.c 				\
						create_functions.c 	\
						destroy_functions.c	\
						analyse_event.c	 	\
						objects.c	 		\


SRC_MAIN		=		main.c

DIR_SRC 		=		$(addprefix src/, $(SRC))

DIR_MAIN 		=		$(addprefix src/, $(SRC_MAIN))

OBJ				=		$(DIR_SRC:.c=.o)

OBJ_MAIN		=		$(DIR_MAIN:.c=.o)

CC				=		gcc

CFLAGS			=		-Wextra -ggdb3

CPPFLAGS		=		-I./include/

LDFLAGS			=		-lcsfml-graphics -lcsfml-system -lcsfml-window

NAME			=		map

RM				=		rm -rf

all:	$(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) src/*.o $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN) vgcore* *.gc*

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re