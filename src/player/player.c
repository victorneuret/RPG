/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** player
*/

#include "render.h"
#include "player.h"
#include "render_window.h"
#include "my_calloc.h"

void draw_player(win_t *win, player_t *player)
{
	render_object(win->sf_win, SPRITE, player->sprite);
}

player_t *init_player(win_t *win)
{
	player_t *player = my_calloc(1, sizeof(player_t));
	textures_t *text = win->game->textures;
	sfIntRect rect = (sfIntRect) {0, 0, 128, 128};

	if (!player)
		return NULL;
	for (; text && !str_eq(text->name, "player"); text = text->next);
	player->sprite = get_sprite_texture_rect(text->texture, &rect);
	player->clock = sfClock_create();
	if (!player->sprite || !player->clock)
		return NULL;
	return player;
}

void destroy_player(player_t *player)
{
	sfSprite_destroy(player->sprite);
	sfClock_destroy(player->clock);
	free(player);
}
