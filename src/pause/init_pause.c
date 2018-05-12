/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_pause
*/

#include <SFML/Graphics.h>

#include <stdbool.h>

#include "pause.h"
#include "my_calloc.h"
#include "game.h"
#include "sprite_utils.h"
#include "texture.h"

bool init_pause(game_t *game)
{
	game->pause = my_calloc(sizeof(pause_t), 1);
	if (!game->pause)
		return false;
	game->pause->texture = get_texture(game->textures, "menu")->texture;
	if (!game->pause->texture)
		return false;
	game->pause->background = get_sprite_texture_rect(game->pause->texture,
				&(sfIntRect) {1920, 2160, 1920, 1080});
	if (!game->pause->background)
		return false;
	return true;
}
