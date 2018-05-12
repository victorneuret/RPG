/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_dash
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "player.h"
#include "music.h"
#include "render.h"
#include "render_window.h"
#include "particle_explosion.h"
#include "stats_menu.h"
#include "music.h"
#include "dash.h"

static void dash_movement(win_t *win, player_t *player, float distance)
{
	sfVector2f pos = player->pos;

	pos.x += X_SPEED * (win->joystick->rx / 100.f * distance) * DASH_MULT;
	pos.y += X_SPEED * (win->joystick->ry / 100.f * distance) * DASH_MULT;
	player->pos = pos;
	create_explosion(win, 10, player->pos, hex_to_rgba(0x75FFE7FF));
	create_explosion(win, 10, player->pos, hex_to_rgba(0x75FFE7FF));
	sfSprite_setPosition(player->sprite, player->pos);
}

void player_dash(win_t *win, player_t *player, bool press, bool pressed)
{
	static sfClock *timer;
	dash_t *dash = win->game->stats_menu->skill_tree->dash;

	dash->current_time = timer ? sfTime_asSeconds(
				sfClock_getElapsedTime(timer)) : 0;
	if (!timer)
		timer = sfClock_create();
	if (dash->current_time < dash->delay || !dash->unlocked)
		return;
	sfSprite_setColor(dash->sprite, hex_to_rgba(0x75FFE7FF));
	if (!press && pressed) {
		play_sfx(win->game->sounds, DASH);
		dash_movement(win, player, dash->distance);
		dash->display = true;
		sfClock_restart(timer);
		return;
	}
	if (press)
		dash->display = true;
}

bool init_dash_sprite(skill_tree_t *skill_tree, sfTexture *tex)
{
	skill_tree->dash->sprite =
		get_sprite_texture_rect(tex, &(sfIntRect){256, 640, 128, 128});
	if (!skill_tree->dash->sprite)
		return false;
	sfSprite_setPosition(skill_tree->dash->sprite, (sfVector2f){1800, 50});
	sfSprite_setScale(skill_tree->dash->sprite, (sfVector2f){0.4, 0.4});
	sfSprite_setColor(skill_tree->dash->sprite, hex_to_rgba(0xCDE6FF96));
	return true;
}

void draw_dash(win_t *win, player_t *player)
{
	sfVector2f pos = player->pos;
	dash_t *dash = win->game->stats_menu->skill_tree->dash;

	render_object(win->sf_win, SPRITE, dash->sprite);
	if (!dash->display)
		return;
	pos.x += X_SPEED * (win->joystick->rx / 100.f * dash->distance) *
								DASH_MULT;
	pos.y += X_SPEED * (win->joystick->ry / 100.f * dash->distance) *
								DASH_MULT;
	sfSprite_setColor(player->sprite, hex_to_rgba(0xE0EDFF96));
	sfSprite_setPosition(player->sprite, pos);
	render_object(win->sf_win, SPRITE, player->sprite);
	sfSprite_setPosition(player->sprite, player->pos);
	sfSprite_setColor(dash->sprite, hex_to_rgba(0xE0EDFF96));
	sfSprite_setColor(player->sprite, hex_to_rgba(0xFFFFFFFF));
	dash->display = false;
}
