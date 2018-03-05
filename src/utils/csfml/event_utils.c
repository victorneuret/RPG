/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event_utils
*/

#include "game/events.h"

int get_mouse_button(sfMouseButton button)
{
	switch (button) {
	case sfMouseRight: return -1;
	case sfMouseLeft: return 1;
	case sfMouseMiddle: return 2;
	default: return 0;
	}
}
