/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** popup_destroy
*/

#include "ui.h"
#include "popup.h"

void destroy_popup(popup_t *popup)
{
	sfClock_destroy(popup->timer);
	sfRectangleShape_destroy(popup->rect);
	sfText_destroy(popup->header);
	sfText_destroy(popup->message);
}
