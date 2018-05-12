/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_dash
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "music.h"
#include "render.h"
#include "render_window.h"
#include "stats_menu.h"

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
									win->dt;
	pos.y += X_SPEED * (win->joystick->ry / 100.f * dash->distance) *
									win->dt;
	sfSprite_setColor(player->sprite, hex_to_rgba(0xE0EDFF96));
	sfSprite_setPosition(player->sprite, pos);
	render_object(win->sf_win, SPRITE, player->sprite);
	sfSprite_setPosition(player->sprite, player->pos);
	sfSprite_setColor(dash->sprite, hex_to_rgba(0xE0EDFF96));
	sfSprite_setColor(player->sprite, hex_to_rgba(0xFFFFFFFF));
	dash->display = false;
}
