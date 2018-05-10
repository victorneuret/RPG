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
#include "text_utils.h"
#include "color_utils.h"
#include "textbox.h"
#include "interaction.h"

void set_textbox_elements(textbox_t *tb, sfFont *font)
{
	sfRectangleShape_setPosition(tb->rect, tb->pos);
	sfRectangleShape_setFillColor(tb->rect, tb->foreground_color);
	sfRectangleShape_setOutlineColor(tb->rect, tb->border_color);
	sfRectangleShape_setOutlineThickness(tb->rect, 2);
	sfRectangleShape_setSize(tb->rect, (sfVector2f) {TEXTBOX_W, TEXTBOX_H});
	sfText_setString(tb->name, "Satoru Iwata:");
	sfText_setColor(tb->name, tb->name_color);
	sfText_setFont(tb->name, font);
	sfText_setStyle(tb->name, sfTextBold);
	sfText_setPosition(tb->name,
		(sfVector2f) {TEXTBOX_POS_X + 10, TEXTBOX_POS_Y + 5});
	sfText_setCharacterSize(tb->name, 20);
}

textbox_t *init_textbox(void)
{
	textbox_t *tb = malloc(sizeof(textbox_t));
	sfFont *font = sfFont_createFromFile(FONT_PATH);

	tb->rect = sfRectangleShape_create();
	tb->name = sfText_create();
	if (!tb || !tb->rect || !tb->name || !font)
		return NULL;
	tb->pos = (sfVector2f) {TEXTBOX_POS_X, TEXTBOX_POS_Y};
	tb->border_color = sfColor_fromRGBA(255, 255, 255, 255);
	tb->foreground_color = sfColor_fromRGBA(0, 0, 0, 150);
	tb->name_color = hex_to_rgb(0x64b5f6);
	tb->state = false;
	set_textbox_elements(tb, font);
	return tb;
}
