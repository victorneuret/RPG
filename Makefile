##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

SRC	=	src/args.c										\
		src/custom/custom_player.c								\
		src/dungeon/free_dungeon.c								\
		src/dungeon/init_dungeon.c								\
		src/dungeon/set_room.c									\
		src/dungeon/init_rooms.c								\
		src/dungeon/portal.c									\
		src/dungeon/init_mini_map.c								\
		src/enemies/enemies.c									\
		src/enemies/enemy_ai.c									\
		src/enemies/enemy_list.c								\
		src/enemies/enemy_bars.c								\
		src/enemies/enemy_death.c								\
		src/enemies/animate_enemy.c								\
		src/game/backgrounds.c									\
		src/game/display/fps.c									\
		src/game/events.c									\
		src/game/events_functions/basic_events.c						\
		src/game/events_functions/exit_intro.c							\
		src/game/gamepad/buttons/joystick_button_abxy.c						\
		src/game/gamepad/buttons/joystick_button_arrow.c					\
		src/game/gamepad/buttons/joystick_button_lb_rb.c					\
		src/game/gamepad/buttons/joystick_button_rt_lt.c					\
		src/game/gamepad/buttons/joystick_button_special.c					\
		src/game/gamepad/buttons/joystick_button_stick.c					\
		src/game/gamepad/joystick.c								\
		src/game/gamepad/move_joystick.c							\
		src/game/gamepad/switch_gamepad.c							\
		src/game/gamepad/update_deadzone_joystick.c						\
		src/game/gamepad/update_joystick_ui.c							\
		src/game/init/init_game.c								\
		src/game/init/load_textures.c								\
		src/game/key_pressed_functions/dir_arrow.c						\
		src/game/key_pressed_functions/pause_resume.c						\
		src/game/key_pressed_functions/toggles.c						\
		src/game/key_pressed_functions/special_actions.c					\
		src/game/key_pressed_functions/to_title_page.c						\
		src/game/key_pressed_functions/window_actions.c						\
		src/game/levels/display_door.c								\
		src/game/levels/obstacle.c								\
		src/game/key_pressed_functions/shoot_arrow.c						\
		src/game/menu/menu_button_function/title_page_functions.c				\
		src/game/menu/options.c									\
		src/game/menu/title_page.c								\
		src/game/menu/slider_parallax.c								\
		src/game/ui/hud/hp_bar.c								\
		src/game/ui/hud/xp_bar.c								\
		src/game/ui/hud/init_hud.c								\
		src/game/ui/button/checkbox_animation.c							\
		src/game/ui/button/checkbox_click.c							\
		src/game/ui/button/init_slider.c							\
		src/game/ui/button/slider_click.c							\
		src/game/ui/button/init_checkbox.c							\
		src/game/ui/button/checkbox_functions.c							\
		src/game/ui/button/button_animation.c							\
		src/game/ui/button/button_click.c							\
		src/game/ui/button/button_text_hover.c							\
		src/game/ui/button/draw_buttons.c							\
		src/game/ui/button/init_button.c							\
		src/game/ui/popup/popup_create.c							\
		src/game/ui/popup/popup_destroy.c							\
		src/game/ui/popup/popup_render.c							\
		src/game/ui/popup/popup_update.c							\
		src/game/ui/text_area/draw_text_area.c							\
		src/game/ui/text_area/init_text_area.c							\
		src/game/ui/text_area/text_area_click.c							\
		src/game/ui/text_area/text_area_write.c							\
		src/game/ui/slider/slider.c								\
		src/game/weather/rain.c									\
		src/game/weather/snow.c									\
		src/game/weather/weather.c								\
		src/game/save/save.c									\
		src/game/save/open_save.c								\
		src/intro/intro.c									\
		src/game/music/init_music.c								\
		src/game/music/music_manager.c								\
		src/game/music/sfx_manager.c								\
		src/my_rpg.c										\
		src/level/level.c									\
		src/particles/effects/particle_shot.c							\
		src/particles/effects/particle_ak.c							\
		src/particles/effects/particle_flame.c							\
		src/particles/effects/particle_shotgun.c						\
		src/particles/effects/particle_rifle.c							\
		src/particles/effects/particle_xp.c							\
		src/particles/effects/particle_heal.c							\
		src/particles/effects/particle_explosion.c						\
		src/particles/effects/particle_fire.c							\
		src/particles/effects/particle_stars.c							\
		src/particles/particle_destroyer.c							\
		src/particles/particle_drawer.c								\
		src/particles/particle_manager.c							\
		src/particles/particle_updater.c							\
		src/pause/init_pause.c									\
		src/pause/render_pause.c								\
		src/player/actions.c									\
		src/player/heal.c									\
		src/player/dash.c									\
		src/player/door_action.c								\
		src/player/door_transition.c								\
		src/player/idle.c									\
		src/player/player.c									\
		src/player/player_utils.c								\
		src/player/update_player.c								\
		src/player/check_obstacle.c								\
		src/player/inventory.c									\
		src/player/drop_inventory.c								\
		src/player/init_inventory.c								\
		src/player/draw_inventory.c								\
		src/player/player_death.c								\
		src/interaction/npc.c									\
		src/interaction/textbox.c								\
		src/interaction/quest.c									\
		src/skill_tree/draw_skill_tree.c							\
		src/skill_tree/update_pos.c								\
		src/skill_tree/init_skill_tree.c							\
		src/skill_tree/skill_hp.c								\
		src/skill_tree/skill_weapon.c								\
		src/skill_tree/skill_dash.c								\
		src/skill_tree/skill_heal.c								\
		src/stats_menu/draw_stat_menu.c								\
		src/stats_menu/init_stat_menu.c								\
		src/stats_menu/update_stat_menu.c							\
		src/interaction/init_npc.c								\
		src/render.c										\
		src/update.c										\
		src/utils/csfml/color_utils.c								\
		src/utils/csfml/coord_utils.c								\
		src/utils/csfml/mouse_utils.c								\
		src/utils/csfml/rectangle_utils.c							\
		src/utils/csfml/sprite_utils.c								\
		src/utils/csfml/text_utils.c								\
		src/utils/my_calloc.c									\
		src/utils/nbr/angle_utils.c								\
		src/utils/nbr/getnbr.c									\
		src/utils/nbr/int_to_str.c								\
		src/utils/nbr/nb_utils.c								\
		src/utils/str/str_utils_1.c								\
		src/utils/str/str_utils_2.c								\
		src/window/change_state.c								\
		src/window/destroy.c									\
		src/window/render_window.c								\
		src/xml/get_node_by_name.c								\
		src/xml/load_xml.c									\
		src/xml/node_utils.c									\
		src/xml/xml_exemple.c									\
		src/xml/parse_xml_player.c								\
		src/xml/parse_xml_item.c								\
		src/xml/parse_xml_enemies.c


SRC_UNIT=	$(filter-out src/main.c, $(SRC))							\
		tests/test_getnbr.c									\
		tests/test_nb_utils.c									\
		tests/test_str_utils_2.c								\
		tests/test_str_utils.c

SRC	+=	src/main.c

CPPFLAGS+=	-Wall -Wextra

CPPFLAGS+=	-I./include										\
		-I./include/dungeon									\
		-I./include/enemies									\
		-I./include/game									\
		-I./include/game/display								\
		-I./include/game/keyboard								\
		-I./include/game/level									\
		-I./include/game/menu									\
		-I./include/game/music									\
		-I./include/game/ui									\
		-I./include/game/ui/hud									\
		-I./include/game/ui/buttons								\
		-I./include/game/ui/popup								\
		-I./include/game/ui/text_area								\
		-I./include/game/ui/title_screen							\
		-I./include/game/weather								\
		-I./include/particles									\
		-I./include/particles/effects								\
		-I./include/stats_menu									\
		-I./include/intro									\
		-I./include/game/music									\
		-I./include/player									\
		-I./include/interaction									\
		-I./include/level									\
		-I./include/pause									\
		-I./include/player									\
		-I./include/utils									\
		-I./include/utils/csfml									\
		-I./include/utils/nbr									\
		-I./include/window									\
		-I./include/xml										\
		-I./extern_libs

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra

LDFLAGS	+=	-lm -lc_graph_prog
LDFLAGS +=	-L./extern_libs -lxmllib

all:	$(NAME)

%.o:		%.c
		@echo -e "[\e[34m$(NAME)\e[39m] : Compiling \e[92m$<\e[39m"
		@$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

$(NAME):	$(OBJ)
		@make --no-print-directory -C extern_libs
		@echo -en "Linking $(NAME) ..."
		@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
		@echo -e " Done"

renolib:	clean $(OBJ)
		@echo -en "Linking $(NAME) ..."
		@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
		@echo -e " Done"

clean:
		@echo -en "Cleaning $(NAME) ..."
		@rm -f $(OBJ)
		@make clean --no-print-directory -C extern_libs
		@echo -e " Done"

fclean:		clean
		@echo -en "FCleaning $(NAME) ..."
		@rm -f $(NAME) tests_run
		@make fclean --no-print-directory -C extern_libs
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

.PHONY:	all clean fclean re tests_run clean_coverage valgrind renolib
