##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

SRC	=	src/args.c                                                                                          \
		src/game/backgrounds.c                                                                              \
		src/game/display/drawer.c                                                                           \
		src/game/display/fps.c                                                                              \
		src/game/events.c                                                                                   \
		src/game/events_functions/basic_events.c                                                            \
		src/game/events_functions/joystick_events.c                                                         \
		src/game/gamepad/buttons/joystick_button_abxy.c                                                     \
		src/game/gamepad/buttons/joystick_button_lb_rb.c                                                    \
		src/game/gamepad/buttons/joystick_button_rt_lt.c                                                    \
		src/game/gamepad/buttons/joystick_button_special.c                                                  \
		src/game/gamepad/buttons/joystick_button_stick.c                                                    \
		src/game/gamepad/joystick.c                                                                         \
		src/game/gamepad/move_joystick.c                                                                    \
		src/game/gamepad/switch_gamepad.c                                                                   \
		src/game/gamepad/update_joystick_ui.c                                                               \
		src/game/init/init_game.c                                                                           \
		src/game/init/load_textures.c                                                                       \
		src/game/key_pressed_functions/pause_resume.c                                                       \
		src/game/key_pressed_functions/toggles.c                                                            \
		src/game/key_pressed_functions/to_title_page.c                                                      \
		src/game/key_pressed_functions/weather_modifiers.c                                                  \
		src/game/key_pressed_functions/window_actions.c                                                     \
		src/game/levels/level_draw.c                                                                        \
		src/game/levels/level_load.c                                                                        \
		src/game/levels/level_unload.c                                                                      \
		src/game/menu/menu_button_function/title_page_functions.c                                           \
		src/game/menu/title_page.c                                                                          \
		src/game/particles/effects/particle_explosion.c                                                     \
		src/game/particles/effects/particle_fire.c                                                          \
		src/game/particles/effects/particle_stars.c                                                         \
		src/game/particles/particle_destroyer.c                                                             \
		src/game/particles/particle_drawer.c                                                                \
		src/game/particles/particle_manager.c                                                               \
		src/game/particles/particle_updater.c                                                               \
		src/game/ui/button/button_animation.c                                                               \
		src/game/ui/button/button_click.c                                                                   \
		src/game/ui/button/button_text_hover.c                                                              \
		src/game/ui/button/draw_buttons.c                                                                   \
		src/game/ui/button/init_button.c                                                                    \
		src/game/ui/popup/popup_create.c                                                                    \
		src/game/ui/popup/popup_destroy.c                                                                   \
		src/game/ui/popup/popup_render.c                                                                    \
		src/game/ui/popup/popup_update.c                                                                    \
		src/game/ui/text_area/draw_text_area.c                                                              \
		src/game/ui/text_area/init_text_area.c                                                              \
		src/game/ui/text_area/text_area_click.c                                                             \
		src/game/ui/text_area/text_area_write.c                                                             \
		src/game/weather/rain.c                                                                             \
		src/game/weather/snow.c                                                                             \
		src/game/weather/weather.c                                                                          \
		src/main.c                                                                                          \
		src/my_rpg.c                                                                                        \
		src/player/player.c                                                                                 \
		src/utils/csfml/color_utils.c                                                                       \
		src/utils/csfml/coord_utils.c                                                                       \
		src/utils/csfml/mouse_utils.c                                                                       \
		src/utils/csfml/rectangle_utils.c                                                                   \
		src/utils/csfml/sprite_utils.c                                                                      \
		src/utils/csfml/text_utils.c                                                                        \
		src/utils/my_calloc.c                                                                               \
		src/utils/nbr/getnbr.c                                                                              \
		src/utils/nbr/int_to_str.c                                                                          \
		src/utils/nbr/nb_utils.c                                                                            \
		src/utils/str/str_utils_1.c                                                                         \
		src/utils/str/str_utils_2.c                                                                         \
		src/window/change_state.c                                                                           \
		src/window/destroy.c                                                                                \
		src/window/render_window.c

SRC_UNIT=	src/args.c                                                                                          \
		src/game/backgrounds.c                                                                              \
		src/game/display/drawer.c                                                                           \
		src/game/display/fps.c                                                                              \
		src/game/events.c                                                                                   \
		src/game/events_functions/basic_events.c                                                            \
		src/game/events_functions/joystick_events.c                                                         \
		src/game/gamepad/buttons/joystick_button_abxy.c                                                     \
		src/game/gamepad/buttons/joystick_button_lb_rb.c                                                    \
		src/game/gamepad/buttons/joystick_button_rt_lt.c                                                    \
		src/game/gamepad/buttons/joystick_button_special.c                                                  \
		src/game/gamepad/buttons/joystick_button_stick.c                                                    \
		src/game/gamepad/joystick.c                                                                         \
		src/game/gamepad/move_joystick.c                                                                    \
		src/game/gamepad/switch_gamepad.c                                                                   \
		src/game/gamepad/update_joystick_ui.c                                                               \
		src/game/init/init_game.c                                                                           \
		src/game/init/load_textures.c                                                                       \
		src/game/key_pressed_functions/pause_resume.c                                                       \
		src/game/key_pressed_functions/toggles.c                                                            \
		src/game/key_pressed_functions/to_title_page.c                                                      \
		src/game/key_pressed_functions/weather_modifiers.c                                                  \
		src/game/key_pressed_functions/window_actions.c                                                     \
		src/game/levels/level_draw.c                                                                        \
		src/game/levels/level_load.c                                                                        \
		src/game/levels/level_unload.c                                                                      \
		src/game/menu/menu_button_function/title_page_functions.c                                           \
		src/game/menu/title_page.c                                                                          \
		src/game/particles/effects/particle_explosion.c                                                     \
		src/game/particles/effects/particle_fire.c                                                          \
		src/game/particles/effects/particle_stars.c                                                         \
		src/game/particles/particle_destroyer.c                                                             \
		src/game/particles/particle_drawer.c                                                                \
		src/game/particles/particle_manager.c                                                               \
		src/game/particles/particle_updater.c                                                               \
		src/game/ui/button/button_animation.c                                                               \
		src/game/ui/button/button_click.c                                                                   \
		src/game/ui/button/button_text_hover.c                                                              \
		src/game/ui/button/draw_buttons.c                                                                   \
		src/game/ui/button/init_button.c                                                                    \
		src/game/ui/popup/popup_create.c                                                                    \
		src/game/ui/popup/popup_destroy.c                                                                   \
		src/game/ui/popup/popup_render.c                                                                    \
		src/game/ui/popup/popup_update.c                                                                    \
		src/game/ui/text_area/draw_text_area.c                                                              \
		src/game/ui/text_area/init_text_area.c                                                              \
		src/game/ui/text_area/text_area_click.c                                                             \
		src/game/ui/text_area/text_area_write.c                                                             \
		src/game/weather/rain.c                                                                             \
		src/game/weather/snow.c                                                                             \
		src/game/weather/weather.c                                                                          \
		src/my_rpg.c                                                                                        \
		src/player/player.c                                                                                 \
		src/utils/csfml/color_utils.c                                                                       \
		src/utils/csfml/coord_utils.c                                                                       \
		src/utils/csfml/mouse_utils.c                                                                       \
		src/utils/csfml/rectangle_utils.c                                                                   \
		src/utils/csfml/sprite_utils.c                                                                      \
		src/utils/csfml/text_utils.c                                                                        \
		src/utils/my_calloc.c                                                                               \
		src/utils/nbr/getnbr.c                                                                              \
		src/utils/nbr/int_to_str.c                                                                          \
		src/utils/nbr/nb_utils.c                                                                            \
		src/utils/str/str_utils_1.c                                                                         \
		src/utils/str/str_utils_2.c                                                                         \
		src/window/change_state.c                                                                           \
		src/window/destroy.c                                                                                \
		src/window/render_window.c                                                                          \
		tests/test_getnbr.c                                                                                 \
		tests/test_nb_utils.c                                                                               \
		tests/test_str_utils_2.c                                                                            \
		tests/test_str_utils.c

CPPFLAGS+=	-I./include                                                                                         \
		-I./include/game                                                                                    \
		-I./include/game/display                                                                            \
		-I./include/game/keyboard                                                                           \
		-I./include/game/levels                                                                             \
		-I./include/game/menu                                                                               \
		-I./include/game/particles                                                                          \
		-I./include/game/particles/effects                                                                  \
		-I./include/game/ui                                                                                 \
		-I./include/game/ui/buttons                                                                         \
		-I./include/game/ui/popup                                                                           \
		-I./include/game/ui/text_area                                                                       \
		-I./include/game/ui/title_screen                                                                    \
		-I./include/game/weather                                                                            \
		-I./include/player                                                                                  \
		-I./include/utils                                                                                   \
		-I./include/utils/csfml                                                                             \
		-I./include/utils/nbr                                                                               \
		-I./include/window

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra

LDFLAGS	+=	-lm
LDFLAGS +=	-lc_graph_prog

all:	$(NAME)

%.o:		%.c
		@echo -e "[\e[34m$(NAME)\e[39m] : Compiling \e[92m$<\e[39m"
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
