/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** title_page
*/

#include "title_page.h"

title_page_t *init_title_page(textures_t *texture)
{
	title_page_t *title_page = malloc(sizeof(title_page_t));
	textures_t *tmp = texture;
	sfFloatRect rect;

	if (!title_page)
		return NULL;
	for (; tmp && !str_eq(tmp->name, "title_page"); tmp = tmp->next);
	title_page->earth = create_sprite(tmp->texture);
	rect = sfSprite_getGlobalBounds(title_page->earth);
	sfSprite_setOrigin(title_page->earth,
			(sfVector2f) {rect.width / 2, rect.height / 2});
	sfSprite_setPosition(title_page->earth, (sfVector2f) {960, 540});
	return title_page;
}

void update_title_page(win_t *win)
{
	sfVector2f mouse = get_mouse_pos(win);

	sfSprite_setPosition(win->game->ui->title_page->earth,
	(sfVector2f) {mouse.x / 25 * -1 + 960, mouse.y / 25 * -1 + 540});
}
