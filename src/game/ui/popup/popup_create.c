/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** popup_create
*/

#include "ui.h"
#include "popup.h"
#include "my_calloc.h"
#include "text_utils.h"
#include "rectangle_utils.h"

static void reset_alpha(popup_t *popup)
{
	sfColor rect = sfRectangleShape_getFillColor(popup->rect);
	sfColor brdr = sfRectangleShape_getOutlineColor(popup->rect);
	sfColor head = sfText_getColor(popup->header);
	sfColor msgs = sfText_getColor(popup->message);

	rect.a = 0;
	brdr.a = 0;
	head.a = 0;
	msgs.a = 0;
	sfRectangleShape_setFillColor(popup->rect, rect);
	sfRectangleShape_setOutlineColor(popup->rect, brdr);
	sfText_setColor(popup->header, head);
	sfText_setColor(popup->message, msgs);
}

static sfColor get_popup_color(popup_type type)
{
	switch (type) {
	case INFO: return sfCyan;
	case WARNING: return sfYellow;
	case ERROR: return sfRed;
	}
	return sfWhite;
}

static char *get_popup_text_type(popup_type type)
{
	switch (type) {
	case INFO: return "Info";
	case WARNING: return "Warning";
	case ERROR: return "Error";
	}
	return "Other";
}

static popup_t *init_popup(char const *text, sfVector2f pos, popup_type type)
{
	popup_t *popup = my_calloc(1, sizeof(popup_t));
	sfFont *font = sfFont_createFromFile("res/fonts/telegrama_render.otf");

	if (!popup || !font)
		return NULL;
	popup->type = type;
	popup->alive = true;
	popup->duration_ms = 3000;
	popup->timer = sfClock_create();
	popup->rect = init_rectangle(pos, (sfVector2f) {400, 150},
				(sfColor) {42, 42, 42, 255});
	popup->header = init_text(font, get_popup_text_type(type),
		(sfVector2f) {pos.x + 20, pos.y + 20}, 25);
	popup->message = init_text(font, text,
		(sfVector2f) {pos.x + 20, pos.y + 60}, 21);
	if (!popup->rect || !popup->header || !popup->message || !popup->timer)
		return NULL;
	sfText_setColor(popup->header, get_popup_color(type));
	sfRectangleShape_setOutlineColor(popup->rect, get_popup_color(type));
	sfRectangleShape_setOutlineThickness(popup->rect, 2.f);
	return popup;
}

void create_popup(ui_t *ui, char const *text, popup_type type)
{
	const sfVector2f pos = (sfVector2f) {50, 50};
	popup_list_t *current = ui->popup_list;
	popup_t *popup = init_popup(text, pos, type);

	if (!popup)
		return;
	for (; current && current->next; current = current->next);
	reset_alpha(popup);
	current->popup = popup;
	current->next = my_calloc(1, sizeof(popup_list_t));
	if (!current->next) {
		free(popup);
		return;
	}
}
