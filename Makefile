##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

SRC	=	$(shell find src -name "*.c")
SRC_UNIT=	$(shell find src -name "*.c" -not -name "main.c") $(shell find tests -name "*.c")

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I./include/
CFLAGS	+=	-lm

ifeq ($(USER), hmaxime)
	CFLAGS +=	-lcsfml-audio
	CFLAGS +=	-lcsfml-window
	CFLAGS +=	-lcsfml-system
	CFLAGS +=	-lcsfml-graphics
else
	CFLAGS +=	-lc_graph_prog
endif

all:	$(NAME)

%.o:		%.c
		@echo -e "[\e[34m$(NAME)\e[39m] : Compiling \e[94m$<\e[39m -> \e[92m$@\e[39m"
		@$(CC) -c $(CFLAGS) -o $@ $<


$(NAME):	$(OBJ)
		@echo -en "Compiling $(NAME) ..."
		@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
		@echo -e " Done"

clean:
		@echo -en "Cleaning $(NAME) ..."
		@rm -f $(OBJ)
		@echo -e " Done"

fclean:		clean
		@echo -en "FCleaning $(NAME) ..."
		@rm -f $(NAME) tests_run
		@echo -e " Done"

re:		fclean all

valgrind:
		@$(CC) -o $(NAME) -g3 $(CFLAGS) $(SRC)

clean_coverage:
		@find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

tests_run:
		@echo -en "Compiling tests binary..."
		@$(CC) $(SRC_UNIT) $(CFLAGS) -lcriterion -o tests_run --coverage
		@echo -e " Done"
		./tests_run

.PHONY:	all clean fclean re tests_run clean_coverage
