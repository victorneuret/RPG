/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** popup_render
*/

#include "ui.h"
#include "popup.h"

static void change_y(popup_t *popup, ssize_t offset)
{
	sfVector2f rect_pos = sfRectangleShape_getPosition(popup->rect);
	sfVector2f text_pos = sfText_getPosition(popup->message);
	sfVector2f type_pos = sfText_getPosition(popup->header);

	rect_pos.y += offset;
	text_pos.y += offset;
	type_pos.y += offset;
	sfRectangleShape_setPosition(popup->rect, rect_pos);
	sfText_setPosition(popup->message, text_pos);
	sfText_setPosition(popup->header, type_pos);
}

static void render_popup(win_t *win, popup_t *popup, size_t offset)
{
	change_y(popup, offset);
	sfRenderWindow_drawRectangleShape(win->sf_win, popup->rect, NULL);
	sfRenderWindow_drawText(win->sf_win, popup->header, NULL);
	sfRenderWindow_drawText(win->sf_win, popup->message, NULL);
	change_y(popup, -offset);
}

void draw_popups(win_t *win, popup_list_t *popups)
{
	popup_list_t *current = popups;
	size_t offset = 0;

	for (; current; current = current->next) {
		if (current->popup && current->popup->alive) {
			render_popup(win, current->popup, offset);
			offset += sfRectangleShape_getSize(
					current->popup->rect).y + 20;
		}
	}
}
