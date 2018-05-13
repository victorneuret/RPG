/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** intro
*/

#include <stdbool.h>
#include <stdint.h>

#include "render_window.h"
#include "change_state.h"
#include "render.h"
#include "macros.h"
#include "intro_struct.h"
#include "particle_explosion.h"
#include "nb_utils.h"
#include "text_utils.h"

static float get_time(sfClock *clock)
{
	return sfTime_asSeconds(sfClock_getElapsedTime(clock));
}

void render_intro(win_t *win, intro_t *intro)
{
	sfText_setColor(intro->text[TEAM],
		sfColor_fromRGBA(255, 255, 255, intro->i));
	sfText_setColor(intro->text[PRESENT],
		sfColor_fromRGBA(255, 150, 0, intro->j));
	render_object(win->sf_win, TEXT, intro->text[TEAM]);
	render_object(win->sf_win, TEXT, intro->text[PRESENT]);
}

static intro_t *init_intro(intro_t *intro)
{
	intro = malloc(sizeof(intro_t));
	intro->text[TEAM] = sfText_create();
	intro->text[PRESENT] = sfText_create();
	intro->intro_font = sfFont_createFromFile(INTRO_FONT);
	intro->timer = sfClock_create();
	if (!intro || !intro->text[TEAM] || !intro->text[PRESENT]
		|| !intro->intro_font
		|| !intro->timer)
		return NULL;
	intro->i = 0;
	intro->j = 0;
	sfText_setFont(intro->text[TEAM], intro->intro_font);
	sfText_setFont(intro->text[PRESENT], intro->intro_font);
	sfText_setCharacterSize(intro->text[TEAM], 200);
	sfText_setCharacterSize(intro->text[PRESENT], 150);
	sfText_setString(intro->text[TEAM], TEAM_TEXT);
	sfText_setString(intro->text[PRESENT], PRESENT_TEXT);
	center_text(intro->text[TEAM], 490);
	center_text(intro->text[PRESENT], 600);
	return intro;
}

static void animate_text(win_t *win, intro_t *intro)
{
	static float elapsed_time = 0.f;
	sfVector2f mouse = get_mouse_pos(win);

	if (elapsed_time > 1.f) {
		intro->i = ((elapsed_time - 1.f) / 2.f) * 255.f;
		intro->i = MIN(intro->i, 255);
	}
	if (elapsed_time > 3.f) {
		intro->j = ((elapsed_time - 3.f) / 3.f) * 255.f;
		intro->j = MIN(intro->j, 255);
	}
	elapsed_time = get_time(intro->timer);
	if (elapsed_time > 7.f)
		win->game_state = TITLE;
	sfText_setPosition(intro->text[TEAM],
	(sfVector2f) {mouse.x / 150 * -1 + 960, mouse.y / 150 * -1 + 540});
	sfText_setPosition(intro->text[PRESENT],
	(sfVector2f) {mouse.x / 40 * -1 + 960, mouse.y / 40 * -1 + 680});
}

bool update_intro(win_t *win, intro_t *intro)
{
	if (!intro) {
		intro = init_intro(intro);
		if (!intro)
			return false;
		win->intro = intro;
	}
	animate_text(win, intro);
	return true;
}
