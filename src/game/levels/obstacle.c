/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** obstacle
*/

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "render_window.h"
#include "dungeon.h"
#include "texture.h"

static sfSprite *init_obstacle_sprite(textures_t *texture)
{
	textures_t *obstacle_texture = get_texture(texture, "rock");
	sfSprite *sprite = get_sprite_texture_rect(obstacle_texture->texture,
						&(sfIntRect) {0, 0, 33, 33});

	// sfSprite_setScale(sprite, (sfVector2f) {5, 5});
	// sfSprite_setOrigin(sprite, (sfVector2f) {
	// 		sfSprite_getGlobalBounds(sprite).width / 2,
	// 		sfSprite_getGlobalBounds(sprite).height / 2});
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
				printf("x: %ld\ty: %ld\n", j * 136 + 166, i * 134 + 166);
				sfSprite_setPosition(sprite, (sfVector2f) {j * 126 + 140, i * 114 + 140});
				sfRenderWindow_drawSprite(win->sf_win, sprite, 0);

				// draw_at_pos(win, sprite, (sfVector2f) {j * 126 + 166, i * 110+ 166}, 0);
			}
	printf("\n");
	// sfSprite_setPosition(sprite, (sfVector2f) {400, 400});
	// sfRenderWindow_drawSprite(win->sf_win, sprite, 0);
	return true;
}
