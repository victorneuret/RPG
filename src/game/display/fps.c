/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** FPS
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

#include "render.h"
#include "render_window.h"
#include "str_utils.h"
#include "color_utils.h"

static sfText *init_text_fps(void)
{
	sfText *fps_text = sfText_create();

	if (!fps_text)
		return 0;
	sfText_setColor(fps_text, sfCyan);
	sfText_setPosition(fps_text, (sfVector2f) {15, 15});
	sfText_setFont(fps_text,
		sfFont_createFromFile("res/fonts/space_mono_regular.ttf"));
	return fps_text;
}

static void update_framerate_text(sfClock *second_tick, char *fps_content,
				size_t *frames)
{
	char *fps_value;

	for (size_t i = 0; i < 16; i++)
		fps_content[i] = 0;
	fps_value = int_to_str(*frames);
	my_strncat(fps_content, fps_value, my_strlen(fps_value));
	my_strncat(fps_content, " fps", my_strlen(" fps"));
	free(fps_value);
	sfClock_restart(second_tick);
	*frames = 0;
}

void draw_fps(win_t *win)
{
	static size_t frames = 0;
	static bool initialized = false;
	static char fps_content[16];
	static sfText *fps_text = 0;
	static sfClock *second_tick = 0;

	if (!initialized) {
		fps_text = init_text_fps();
		second_tick = sfClock_create();
		initialized = true;
		my_strncat(fps_content, "...", 3);
	}
	if (!fps_text || !second_tick)
		return;
	frames++;
	if (sfTime_asSeconds(sfClock_getElapsedTime(second_tick)) >= 1.0)
		update_framerate_text(second_tick, fps_content, &frames);
	sfText_setString(fps_text, fps_content);
	render_object(win->sf_win, TEXT, fps_text);
}
