/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** Main game logic
*/

#include "my_rpg.h"

// DEBUG
void create_objects(win_t *win)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfRectangleShape *rect_bis = sfRectangleShape_create();

	sfRectangleShape_setPosition(rect, (sfVector2f){200, 200});
	sfRectangleShape_setSize(rect, (sfVector2f){470, 180});
	sfRectangleShape_setFillColor(rect, sfColor_fromRGB(0, 0, 255));

	sfRectangleShape_setPosition(rect_bis, (sfVector2f){400, 400});
	sfRectangleShape_setSize(rect_bis, (sfVector2f){470, 180});
	sfRectangleShape_setFillColor(rect_bis, sfColor_fromRGB(255, 0, 0));

	sfRenderWindow_drawRectangleShape(win->sf_win, rect, NULL);
	sfRenderWindow_drawRectangleShape(win->sf_win, rect_bis, NULL);
	sfRenderWindow_display(win->sf_win);

	sfRectangleShape_destroy(rect);
	sfRectangleShape_destroy(rect_bis);
}
