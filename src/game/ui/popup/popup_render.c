/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** popup_render
*/

#include "ui.h"
#include "popup.h"

static void render_popup(win_t *win, popup_t *popup)
{
	sfRenderWindow_drawRectangleShape(win->sf_win, popup->rect, NULL);
	sfRenderWindow_drawText(win->sf_win, popup->header, NULL);
	sfRenderWindow_drawText(win->sf_win, popup->message, NULL);
}

void draw_popups(win_t *win, popup_list_t *popups)
{
	popup_list_t *current = popups;

	for (; current; current = current->next)
		if (current->popup && current->popup->alive)
			render_popup(win, current->popup);
}
