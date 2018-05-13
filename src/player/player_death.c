/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player_death
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#include "hud.h"
#include "render.h"
#include "render_window.h"
#include "change_state.h"
#include "text_utils.h"

static const char *GAME_OVER_FONT = "res/fonts/isaac_sans.ttf";

sfText *init_game_over(void)
{
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile(GAME_OVER_FONT);

	if (!text || !font)
		return NULL;
	sfText_setFont(text, font);
	sfText_setString(text, "Game Over..");
	sfText_setCharacterSize(text, 150);
	sfText_setColor(text, sfWhite);
	center_text(text, WIN_MAX_H / 2);
	return text;
}

void player_is_alive(win_t *win, bar_t *hp)
{
	sfColor color;
	player_t *player = win->game->player;

	if (hp->value == 0 && win->game_state == GAME) {
		color = sfRectangleShape_getFillColor(player->shade);
		color.a = 0;
		sfRectangleShape_setFillColor(player->shade, color);
		render_object(win->sf_win, TEXT, win->game->player->game_over);
		player->alive = false;
	}

}
