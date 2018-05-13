/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** custom_player
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#include "render.h"
#include "player.h"
#include "change_state.h"
#include "color_utils.h"

sfRectangleShape *init_custom_shape(void)
{
	sfRectangleShape *shape = sfRectangleShape_create();

	if (!shape)
		return NULL;
	sfRectangleShape_setSize(shape, (sfVector2f) {WIN_MAX_W, WIN_MAX_H});
	sfRectangleShape_setFillColor(shape, hex_to_rgb(0x455a64));
	return shape;
}

void render_custom_player(win_t *win)
{
	static bool set_player = true;
	player_t *player = win->game->player;

	if (set_player) {
		sfSprite_setPosition(player->sprite, (sfVector2f) {WIN_MAX_W / 2, WIN_MAX_H / 4});
		sfSprite_setTextureRect(player->sprite, (sfIntRect) {0, 530, 128, 130});
		set_player = false;
	}
	render_object(win->sf_win, SHAPE, win->game->ui->custom_shape);
	if (sfClock_getElapsedTime(player->timer).microseconds > 300000) {
		animate_sprite(player->sprite,
			sfSprite_getGlobalBounds(player->sprite).width, 2);
		sfClock_restart(player->timer);
	}
	render_object(win->sf_win, SPRITE, player->sprite);
}

void custom_to_play(win_t *win)
{
	change_state(win, GAME);
}
