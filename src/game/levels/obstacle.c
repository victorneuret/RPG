/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** obstacle
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>

#include <stdbool.h>

#include "render_window.h"
#include "dungeon.h"
#include "sprite_utils.h"
#include "texture.h"

static sfSprite *init_obstacle_sprite(textures_t *texture)
{
	textures_t *obstacle_texture = get_texture(texture, "rock");
	sfSprite *sprite = create_sprite(obstacle_texture->texture);

	sfSprite_setScale(sprite, (sfVector2f) {4.83, 4.25});
	return sprite;
}

bool draw_obstacle(room_t *room, win_t *win)
{
	static sfSprite *sprite = NULL;

	if (!sprite) {
		sprite = init_obstacle_sprite(win->game->textures);
		if (!sprite)
			return false;
	}
	for (size_t i = 0; room->cells[i]; i++)
		for (size_t j = 0; room->cells[i][j]; j++)
			if (room->cells[i][j] == 'X') {
				sfSprite_setPosition(sprite, (sfVector2f) {j * 118.5 + 190, i * 100 + 190});
				sfRenderWindow_drawSprite(win->sf_win, sprite, 0);
			}
	return true;
}
