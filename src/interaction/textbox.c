/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** textbox
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "render_window.h"
#include "textbox.h"

static const uint16_t TEXTBOX_W = 900;
static const uint16_t TEXTBOX_H = 100;
static const uint16_t TEXTBOX_POS_X = (WIN_MAX_W / 2) - (TEXTBOX_W / 2);
static const uint16_t TEXTBOX_POS_Y = WIN_MAX_H - TEXTBOX_H - 50;

textbox_t *init_textbox(void)
{
	textbox_t *tb = malloc(sizeof(textbox_t));

	tb->rect = sfRectangleShape_create();
	tb->name = sfText_create();
	tb->text = sfText_create();
	if (!tb || !tb->rect || !tb->name || !tb->text)
		return NULL;
	tb->pos = (sfVector2f) {TEXTBOX_POS_X, TEXTBOX_POS_Y};
	tb->border_color = sfColor_fromRGBA(255, 255, 255, 255);
	tb->foreground_color = sfColor_fromRGBA(0, 0, 0, 150);
	tb->state = false;
	sfRectangleShape_setPosition(tb->rect, tb->pos);
	sfRectangleShape_setFillColor(tb->rect, tb->foreground_color);
	sfRectangleShape_setOutlineColor(tb->rect, tb->border_color);
	sfRectangleShape_setOutlineThickness(tb->rect, 4);
	sfRectangleShape_setSize(tb->rect, (sfVector2f) {TEXTBOX_W, TEXTBOX_H});
	return tb;
}
