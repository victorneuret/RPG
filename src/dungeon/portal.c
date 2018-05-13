/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** portal
*/

#include <SFML/Graphics.h>

#include <SFML/Audio.h>
#include <stdbool.h>

#include "dungeon.h"
#include "texture.h"
#include "sprite_utils.h"
#include "player.h"
#include "level.h"
#include "nb_utils.h"
#include "music.h"

bool init_portal(dungeon_t *dungeon, game_t *game)
{
	sfTexture *texture = get_texture(game->textures, "portal")->texture;

	if (!texture)
		return false;
	dungeon->portal = get_sprite_texture_rect(texture,
				&(sfIntRect) {0, 0, 320, 320});
	if (!dungeon->portal)
		return false;
	sfSprite_setPosition(dungeon->portal, (sfVector2f)
			{WIN_MAX_W / 2 - 160, WIN_MAX_H / 2 - 160});
	return true;
}

static void update_portal(player_t *player, win_t *win)
{
	sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);

	if (sfFloatRect_contains(&rect, WIN_MAX_W / 2, WIN_MAX_H / 2)) {
		play_sfx(win->game->sounds, TELEPORT);
		load_level(&win->game->level,
				rand_int(0, (int) ENV_COUNT - 1), win);
		win->game->dungeon->cleared = false;
		win->game->dungeon->transition = true;
	}
}

void draw_portal(dungeon_t *dungeon, win_t *win)
{
	if (dungeon->act_room != 0 || !dungeon->cleared) {
		sfMusic_pause(win->game->sounds->sfx[PORTAL].music);
		return;
	}
	if (sfMusic_getStatus(win->game->sounds->sfx[PORTAL].music) !=
								sfPlaying)
		play_sfx(win->game->sounds, PORTAL);
	animate_sprite(dungeon->portal,
			sfSprite_getGlobalBounds(dungeon->portal).width, 9);
	sfRenderWindow_drawSprite(win->sf_win, dungeon->portal, 0);
	update_portal(win->game->player, win);
}
