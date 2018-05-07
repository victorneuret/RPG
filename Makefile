##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

SRC	=	src/args.c                                                                                          \
		src/dungeon/free_dungeon.c                                                                          \
		src/dungeon/init_dungeon.c                                                                          \
		src/dungeon/set_room.c										    \
		src/dungeon/init_rooms.c                                                                            \
		src/dungeon/print_dungeon.c                                                                         \
		src/game/backgrounds.c                                                                              \
		src/game/display/fps.c                                                                              \
		src/game/events.c                                                                                   \
		src/game/events_functions/basic_events.c                                                            \
		src/game/events_functions/exit_intro.c                                                              \
		src/game/events_functions/joystick_events.c                                                         \
		src/game/gamepad/buttons/joystick_button_abxy.c                                                     \
		src/game/gamepad/buttons/joystick_button_lb_rb.c                                                    \
		src/game/gamepad/buttons/joystick_button_rt_lt.c                                                    \
		src/game/gamepad/buttons/joystick_button_special.c                                                  \
		src/game/gamepad/buttons/joystick_button_stick.c                                                    \
		src/game/gamepad/joystick.c                                                                         \
		src/game/gamepad/move_joystick.c                                                                    \
		src/game/gamepad/switch_gamepad.c                                                                   \
		src/game/gamepad/update_deadzone_joystick.c                                                         \
		src/game/gamepad/update_joystick_ui.c                                                               \
		src/game/init/init_game.c                                                                           \
		src/game/init/load_textures.c                                                                       \
		src/game/key_pressed_functions/dir_arrow.c                                                          \
		src/game/key_pressed_functions/pause_resume.c                                                       \
		src/game/key_pressed_functions/toggles.c                                                            \
		src/game/key_pressed_functions/special_actions.c                                                    \
		src/game/key_pressed_functions/to_title_page.c                                                      \
		src/game/key_pressed_functions/window_actions.c                                                     \
		src/game/levels/display_door.c                                                                      \
		src/game/levels/obstacle.c									    \
		src/game/key_pressed_functions/shoot_arrow.c							    \
		src/game/menu/menu_button_function/title_page_functions.c                                           \
		src/game/menu/options.c                                                                             \
		src/game/menu/title_page.c                                                                          \
		src/game/particles/effects/particle_shot.c                                                          \
		src/game/particles/effects/particle_explosion.c                                                     \
		src/game/particles/effects/particle_fire.c                                                          \
		src/game/particles/effects/particle_stars.c                                                         \
		src/game/particles/particle_destroyer.c                                                             \
		src/game/particles/particle_drawer.c                                                                \
		src/game/particles/particle_manager.c                                                               \
		src/game/particles/particle_updater.c                                                               \
		src/game/ui/button/checkbox_animation.c                                                             \
		src/game/ui/button/checkbox_click.c                                                                 \
		src/game/ui/button/init_checkbox.c                                                                  \
		src/game/ui/button/checkbox_functions.c                                                             \
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
		src/intro/intro.c                                                                                   \
		src/game/music/init_music.c                                                                         \
		src/game/music/music_manager.c                                                                      \
		src/game/music/sfx_manager.c                                                                        \
		src/my_rpg.c                                                                                        \
		src/level/level.c                                                                                   \
		src/player/actions.c										    \
		src/player/door_action.c									    \
		src/player/door_transition.c                                                                        \
		src/player/idle.c										    \
		src/player/player.c                                                                                 \
		src/player/update_player.c                                                                          \
		src/player/check_obstacle.c									    \
		src/render.c                                                                                        \
		src/utils/csfml/color_utils.c                                                                       \
		src/utils/csfml/coord_utils.c                                                                       \
		src/utils/csfml/mouse_utils.c                                                                       \
		src/utils/csfml/rectangle_utils.c                                                                   \
		src/utils/csfml/sprite_utils.c                                                                      \
		src/utils/csfml/text_utils.c                                                                        \
		src/utils/my_calloc.c                                                                               \
		src/utils/nbr/angle_utils.c                                                                         \
		src/utils/nbr/getnbr.c                                                                              \
		src/utils/nbr/int_to_str.c                                                                          \
		src/utils/nbr/nb_utils.c                                                                            \
		src/utils/str/str_utils_1.c                                                                         \
		src/utils/str/str_utils_2.c                                                                         \
		src/window/change_state.c                                                                           \
		src/window/destroy.c                                                                                \
		src/window/render_window.c                                                                          \
		src/xml/get_node_by_name.c                                                                          \
		src/xml/load_xml.c                                                                                  \
		src/xml/node_utils.c                                                                                \
		src/xml/xml_exemple.c

SRC_UNIT=	$(filter-out src/main.c, $(SRC)) \
		tests/test_getnbr.c                                                                                 \
		tests/test_nb_utils.c                                                                               \
		tests/test_str_utils_2.c                                                                            \
		tests/test_str_utils.c

SRC	+=	src/main.c

CPPFLAGS+=	-Wall -Wextra

CPPFLAGS+=	-I./include                                                                                         \
		-I./include/dungeon                                                                                 \
		-I./include/game                                                                                    \
		-I./include/game/display                                                                            \
		-I./include/game/keyboard                                                                           \
		-I./include/game/level                                                                              \
		-I./include/game/menu                                                                               \
		-I./include/game/music                                                                              \
		-I./include/game/particles                                                                          \
		-I./include/game/particles/effects                                                                  \
		-I./include/game/ui                                                                                 \
		-I./include/game/ui/buttons                                                                         \
		-I./include/game/ui/popup                                                                           \
		-I./include/game/ui/text_area                                                                       \
		-I./include/game/ui/title_screen                                                                    \
		-I./include/game/weather                                                                            \
		-I./include/intro                                                                                   \
		-I./include/game/music                                                                              \
		-I./include/player                                                                                  \
		-I./include/level                                                                                   \
		-I./include/player                                                                                  \
		-I./include/utils                                                                                   \
		-I./include/utils/csfml                                                                             \
		-I./include/utils/nbr                                                                               \
		-I./include/window                                                                                  \
		-I./include/xml

CPPFLAGS +=	$(shell xml2-config --cflags)

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra

LDFLAGS	+=	-lm -lc_graph_prog
LDFLAGS +=	$(shell xml2-config --libs)

all:	$(NAME)

%.o:		%.c
		@echo -e "[\e[34m$(NAME)\e[39m] : Compiling \e[92m$<\e[39m"
		@$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

$(NAME):	$(OBJ)
		@echo -en "Compiling $(NAME) ..."
		@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
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
		@$(CC) -o $(NAME) -g3 $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(SRC)

clean_coverage:
		find . \( -name '*.gcda' -o -name '*.gcno' -o -name '*.gcov' \) -delete

tests_run:
		@echo -en "Compiling tests binary..."
		@$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC_UNIT) $(LDFLAGS) -lcriterion -o tests_run --coverage
		@echo -e " Done"
		./tests_run

check_compilation:	re valgrind tests_run
		@make --no-print-directory clean_coverage
		@make --no-print-directory fclean

.PHONY:	all clean fclean re tests_run clean_coverage valgrind check_compilation
