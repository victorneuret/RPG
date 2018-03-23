/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** popup_update
*/

#include "ui.h"
#include "popup.h"

static void set_popup_opacity(popup_t *popup, double factor)
{
	sfColor rect = sfRectangleShape_getFillColor(popup->rect);
	sfColor brdr = sfRectangleShape_getOutlineColor(popup->rect);
	sfColor type = sfText_getFillColor(popup->header);
	sfColor msgs = sfText_getFillColor(popup->message);

	rect.a = factor * 255.f;
	brdr.a = factor * 255.f;
	type.a = factor * 255.f;
	msgs.a = factor * 255.f;
	sfRectangleShape_setFillColor(popup->rect, rect);
	sfRectangleShape_setOutlineColor(popup->rect, brdr);
	sfText_setFillColor(popup->header, type);
	sfText_setFillColor(popup->message, msgs);
}

static void update_popup(popup_t *popup)
{
	uint64_t current_time = sfTime_asMilliseconds(
				sfClock_getElapsedTime(popup->timer));
	static const double fade_time = 1000.f;

	if (current_time >= popup->duration_ms + fade_time) {
		popup->alive = false;
		destroy_popup(popup);
		return;
	}
	if (current_time <= fade_time / 2.f)
		set_popup_opacity(popup, current_time / (fade_time / 2.f));
	else if (current_time >= popup->duration_ms + fade_time / 2.f)
		set_popup_opacity(popup,
			(popup->duration_ms + fade_time - current_time) /
			(fade_time / 2.f));
	else
		set_popup_opacity(popup, 1.f);
}

void update_popups(popup_list_t *popups)
{
	popup_list_t *current = popups;

	for (; current; current = current->next)
		if (current->popup && current->popup->alive)
			update_popup(current->popup);
}
