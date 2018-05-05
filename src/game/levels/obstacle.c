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

static void check_position(char **map, sfVector2i pos, sfSprite *sprite,
				win_t *win)
{
	if (map[pos.y][pos.x] == 'X') {
		sfSprite_setPosition(sprite, (sfVector2f)
			{pos.x * ROCK_W + WALL_SIZE_ROCK,
			pos.y * ROCK_H + WALL_SIZE_ROCK});
		sfRenderWindow_drawSprite(win->sf_win, sprite, 0);
	}
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
			check_position(room->cells, (sfVector2i) {j, i},
					sprite, win);
	return true;
}
