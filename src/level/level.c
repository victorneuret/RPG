/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level
*/

#include "my_rpg.h"
#include "level.h"
#include "dungeon.h"

static const char *TEXTURE_PATH = "res/levels/level_textures.png";

static void init_position(level_t const *level)
{
	sfSprite_setScale(level->top_r, (sfVector2f) { -1, 1 });
	sfSprite_setScale(level->bot_l, (sfVector2f) { 1, -1 });
	sfSprite_setScale(level->bot_r, (sfVector2f) { -1, -1 });
	sfSprite_setPosition(level->top_l, (sfVector2f) { 0, 0 });
	sfSprite_setPosition(level->top_r, (sfVector2f) { ENV_W * 2, 0 });
	sfSprite_setPosition(level->bot_l, (sfVector2f) { 0, ENV_H * 2 });
	sfSprite_setPosition(level->bot_r,
					(sfVector2f) { ENV_W * 2, ENV_H * 2 });
}

static bool load_sprites(sfTexture const *texture,
			level_t *level, env_name_t env_name)
{
	level->top_l = sfSprite_create();
	level->top_r = sfSprite_create();
	level->bot_l = sfSprite_create();
	level->bot_r = sfSprite_create();
	if (!level->top_l || !level->top_l || !level->top_l || !level->top_l)
		return false;
	sfSprite_setTexture(level->top_l, texture, false);
	sfSprite_setTexture(level->top_r, texture, false);
	sfSprite_setTexture(level->bot_l, texture, false);
	sfSprite_setTexture(level->bot_r, texture, false);
	sfSprite_setTextureRect(level->top_l, env_list[env_name].texture_rect);
	sfSprite_setTextureRect(level->top_r, env_list[env_name].texture_rect);
	sfSprite_setTextureRect(level->bot_l, env_list[env_name].texture_rect);
	sfSprite_setTextureRect(level->bot_r, env_list[env_name].texture_rect);
	init_position(level);
	return true;
}

void draw_level(sfRenderWindow *window, level_t const *level, win_t *win)
{
	sfRenderWindow_drawSprite(window, level->top_l, NULL);
	sfRenderWindow_drawSprite(window, level->top_r, NULL);
	sfRenderWindow_drawSprite(window, level->bot_l, NULL);
	sfRenderWindow_drawSprite(window, level->bot_r, NULL);
	if (!display_door(
		win->game->rooms[win->game->dungeon->act_room], win))
		return;
	if (!draw_obstacle(
		win->game->rooms[win->game->dungeon->act_room], win))
		return;
}

bool load_level(level_t **level, env_name_t env_name, win_t *win)
{
	static sfTexture *texture = NULL;

	if (*level)
		unload_level(*level);
	if (!texture) {
		texture = sfTexture_createFromFile(TEXTURE_PATH, NULL);
		if (!texture)
			return false;
		sfTexture_setSmooth(texture, true);
	}
	free(*level);
	*level = malloc(sizeof(level_t));
	if (!*level)
		return false;
	place_rooms(win->game->dungeon);
	win->game->dungeon->act_room = 0;
	win->game->dungeon->door_open = true;
	if (!init_rooms(win))
		return false;
	return load_sprites(texture, *level, env_name);
}

void unload_level(level_t *level)
{
	if (!level)
		return;
	sfSprite_destroy(level->top_l);
	sfSprite_destroy(level->top_r);
	sfSprite_destroy(level->bot_l);
	sfSprite_destroy(level->bot_r);
}
