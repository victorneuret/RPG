/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** buttons
*/

#include "render_window.h"

typedef struct {
	game_status game_state;
	sfIntRect rect;
	sfVector2f pos;
	char *text_hover;
	sfColor color;
	sfColor hover_color;
	sfSprite *sprite;
	void (*func)(win_t *win);
} button_declaration_t;

static const button_declaration_t buttons[] = {
	{
		ALL,
		(sfIntRect) {0, 0, 64, 64},
		(sfVector2f) {500, 500},
		"load",
		sfBlue,
		sfCyan,
		NULL,
		NULL
	},
	{
		ALL,
		(sfIntRect) {0, 32, 64, 64},
		(sfVector2f) {500, 600},
		"Hello",
		sfMagenta,
		sfWhite,
		NULL,
		NULL
	},
	{ALL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL}
};
