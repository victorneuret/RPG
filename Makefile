##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

SRC	=	src/main.c						\
		src/args.c						\
		src/utils/csfml/color_utils.c				\
		src/utils/csfml/mouse_utils.c				\
		src/utils/my_calloc.c					\
		src/utils/str/str_utils_2.c				\
		src/utils/str/str_utils_1.c				\
		src/utils/nbr/nb_utils.c				\
		src/utils/nbr/getnbr.c					\
		src/utils/nbr/int_to_str.c				\
		src/game/events_functions/basic_events.c		\
		src/game/particles/particle_updater.c			\
		src/game/particles/particle_drawer.c			\
		src/game/particles/effects/particle_explosion.c		\
		src/game/particles/effects/particle_stars.c		\
		src/game/particles/particle_destroyer.c			\
		src/game/particles/particle_manager.c			\
		src/game/events.c					\
		src/game/backgrounds.c					\
		src/game/display/fps.c					\
		src/game/display/drawer.c				\
		src/game/key_pressed_functions/window_actions.c		\
		src/game/key_pressed_functions/pause_resume.c		\
		src/game/key_pressed_functions/toggles.c		\
		src/my_rpg.c						\
		src/window/render_window.c				\
		src/window/destroy.c

SRC_UNIT=	src/args.c						\
		src/utils/csfml/color_utils.c				\
		src/utils/csfml/mouse_utils.c				\
		src/utils/my_calloc.c					\
		src/utils/str/str_utils_2.c				\
		src/utils/str/str_utils_1.c				\
		src/utils/nbr/nb_utils.c				\
		src/utils/nbr/getnbr.c					\
		src/utils/nbr/int_to_str.c				\
		src/game/events_functions/basic_events.c		\
		src/game/particles/particle_updater.c			\
		src/game/particles/particle_drawer.c			\
		src/game/particles/effects/particle_explosion.c		\
		src/game/particles/effects/particle_stars.c		\
		src/game/particles/particle_destroyer.c			\
		src/game/particles/particle_manager.c			\
		src/game/events.c					\
		src/game/backgrounds.c					\
		src/game/display/fps.c					\
		src/game/display/drawer.c				\
		src/game/key_pressed_functions/window_actions.c		\
		src/game/key_pressed_functions/pause_resume.c		\
		src/game/key_pressed_functions/toggles.c		\
		src/my_rpg.c						\
		src/window/render_window.c				\
		src/window/destroy.c					\
		tests/test_getnbr.c					\
		tests/test_str_utils.c					\
		tests/test_nb_utils.c					\
		tests/test_str_utils_2.c

CPPFLAGS+=	-I include						\
		-I include/utils					\
		-I include/utils/csfml					\
		-I include/utils/nbr					\
		-I include/game						\
		-I include/game/particles				\
		-I include/game/particles/effects			\
		-I include/game/display					\
		-I include/game/keyboard				\
		-I include/window

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra

LDFLAGS	+=	-lm

ifeq ($(USER), hmaxime)
	LDFLAGS +=	-lcsfml-audio
	LDFLAGS +=	-lcsfml-window
	LDFLAGS +=	-lcsfml-system
	LDFLAGS +=	-lcsfml-graphics
else
	LDFLAGS +=	-lc_graph_prog
endif

all:	$(NAME)

%.o:		%.c
		@echo -e "[\e[34m$(NAME)\e[39m] : Compiling \e[94m$<\e[39m -> \e[92m$@\e[39m"
		@$(CC) -c $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $@ $<

$(NAME):	$(OBJ)
		@echo -en "Compiling $(NAME) ..."
		@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)
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
		@$(CC) -o $(NAME) -g3 $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) $(SRC)

clean_coverage:
		@find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

tests_run:
		@echo -en "Compiling tests binary..."
		@$(CC) $(SRC_UNIT) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -lcriterion -o tests_run --coverage
		@echo -e " Done"
		./tests_run

check_compilation:	re valgrind tests_run
		@make --no-print-directory clean_coverage
		@make --no-print-directory fclean

.PHONY:	all clean fclean re tests_run clean_coverage valgrind check_compilation
