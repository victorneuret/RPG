/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display_door
*/

#include <stdbool.h>

#include "dungeon.h"
#include "render_window.h"
#include "sprite_utils.h"
#include "level.h"

static sfSprite *init_door_sprite(textures_t *texture, dungeon_t *dungeon)
{
	textures_t *door = texture;
	sfSprite *sprite;
	sfIntRect rect = (dungeon->door_open) ? (sfIntRect) {0, 0, 245, 165}
					: (sfIntRect) {245, 0, 245, 165};

	while (door && !str_eq(door->name, "door"))
		door = door->next;
	if (!door)
		return NULL;
	sprite = get_sprite_texture_rect(door->texture,
			&rect);
	sfSprite_setOrigin(sprite, (sfVector2f) {
			sfSprite_getGlobalBounds(sprite).width / 2,
			sfSprite_getGlobalBounds(sprite).height / 2});
	return sprite;
}

void draw_at_pos(win_t *win, sfSprite *sprite, sfVector2f pos,
			int16_t rotation)
{
	sfSprite_setPosition(sprite, pos);
	sfSprite_rotate(sprite, rotation);
	sfRenderWindow_drawSprite(win->sf_win, sprite, 0);
	sfSprite_rotate(sprite, rotation * -1);
}

void draw_doors(room_t *room, win_t *win, sfSprite *door_sprite)
{
	if (room->door_up)
		draw_at_pos(win, door_sprite,
				(sfVector2f) {X_DOOR_UP, Y_DOOR_UP}, 0);
	if (room->door_down)
		draw_at_pos(win, door_sprite,
				(sfVector2f) {X_DOOR_DOWN, Y_DOOR_DOWN}, 180);
	if (room->door_right)
		draw_at_pos(win, door_sprite,
				(sfVector2f) {X_DOOR_RIGHT, Y_DOOR_RIGHT}, 90);
	if (room->door_left)
		draw_at_pos(win, door_sprite,
				(sfVector2f) {X_DOOR_LEFT, Y_DOOR_LEFT}, -90);
}

bool display_door(room_t *room, win_t *win)
{
	static sfSprite *door_sprite = NULL;
	sfIntRect rect = (win->game->dungeon->door_open) ?
		(sfIntRect) {0, 0, 245, 165} : (sfIntRect) {245, 0, 245, 165};

	if (!door_sprite) {
		door_sprite = init_door_sprite(win->game->textures,
						win->game->dungeon);
		if (!door_sprite)
			return false;
	}
	sfSprite_setTextureRect(door_sprite, rect);
	draw_doors(room, win, door_sprite);
	return true;
}
