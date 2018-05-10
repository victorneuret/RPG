/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** xp_bar
*/

#include <SFML/Graphics.h>

#include "render_window.h"
#include "particle_explosion.h"
#include "color_utils.h"
#include "popup.h"

static void update_xp_bar(player_t *player)
{
	if (player->xp->value < 0)
		player->xp->value = 0;
}

static void reset_bar(player_t *player, float x_pos, win_t *win)
{
	play_sfx(win->game->sounds, LEVEL_UP);
	sfRectangleShape_setSize(player->xp->bar,
			(sfVector2f) {x_pos, XP_HEIGHT});
	create_explosion(win, 3, (sfVector2f){x_pos, 1070},
			hex_to_rgb(0xFFEB3B));
	if (win->game_state == GAME)
		create_popup(win->game->ui, "Level up!", INFO);
	player->level += 1;
	player->skill_point += 1;
	sfText_setString(player->xp->text, int_to_str(player->level));
	text_right(player->xp->text, WIN_MAX_W - 20, 1030);
}

static void play_bar_sound(win_t *win)
{
	static sfClock *timer;
	uint32_t current_time = timer ? sfTime_asMilliseconds(
				sfClock_getElapsedTime(timer)) : 0;

	if (!timer)
		timer = sfClock_create();
	if (current_time > 800.f) {
		play_sfx(win->game->sounds, XP);
		sfClock_restart(timer);
	}
}

static void bar_animation(win_t *win, player_t *player)
{
	float x_pos;
	static uint16_t xp = 0;

	if (xp < player->xp->value && xp < player->xp->max_value) {
		play_bar_sound(win);
		xp += 2 * player->level;
		x_pos = XP_WIDTH / (float) player->xp->max_value * xp;
		sfRectangleShape_setSize(player->xp->bar,
				(sfVector2f) {x_pos, XP_HEIGHT});
		create_explosion(win, 3, (sfVector2f){x_pos, 1070},
				hex_to_rgb(0xFFEB3B));
	} else if (xp >= player->xp->max_value) {
		xp = 0;
		player->xp->value = player->xp->value - player->xp->max_value;
		player->xp->max_value *= player->xp->mult;
		x_pos = XP_WIDTH / (float) player->xp->max_value * xp;
		reset_bar(player, x_pos, win);
	}
}

void display_xp_bar(win_t *win)
{
	static int16_t value = 0;

	if (value != win->game->player->xp->value)
		update_xp_bar(win->game->player);
	bar_animation(win, win->game->player);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->xp->back_bar, 0);
	sfRenderWindow_drawRectangleShape(win->sf_win,
		win->game->player->xp->bar, 0);
	sfRenderWindow_drawText(win->sf_win, win->game->player->xp->text, 0);
	value = win->game->player->xp->value;
}
