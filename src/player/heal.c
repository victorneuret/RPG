/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** heal
*/

#include <SFML/Graphics.h>

#include "heal.h"
#include "render_window.h"
#include "particle_heal.h"
#include "stats_menu.h"

static bool init_skill_heal_sprite(win_t *win, heal_t *heal)
{
	heal->sprite = sfSprite_copy(
			win->game->stats_menu->skill_tree->dash->sprite);
	if (!heal->sprite)
		return false;
	sfSprite_setTextureRect(heal->sprite, (sfIntRect) {384, 640, 128, 128});
	sfSprite_setPosition(heal->sprite, (sfVector2f) {230, 950});
	return true;
}

void print_heal(win_t *win, heal_t *heal)
{
	static bool first = true;

	if (first)
		if (!init_skill_heal_sprite(win, heal))
			return;
	if (heal->unlocked && sfTime_asSeconds(sfClock_getElapsedTime(heal->timer)) >= heal->delay_sec)
		sfSprite_setColor(heal->sprite, hex_to_rgba(0x75FFE7FF));
	else
		sfSprite_setColor(heal->sprite, hex_to_rgba(0xE0EDFFC8));
	sfRenderWindow_drawSprite(win->sf_win, heal->sprite, 0);
	first = false;
}

void heal_player(win_t *win, heal_t *heal)
{
	const player_t *player = win->game->player;

	if (!heal->timer) {
		heal->timer = sfClock_create();
		if (!heal->timer)
			return;
	}
	if (!heal->unlocked || player->hp->value >= player->hp->max_value)
		return;
	if (sfTime_asSeconds(sfClock_getElapsedTime(heal->timer))
						< heal->delay_sec)
		return;
	particle_heal(win, player->hp->max_value * heal->prct, player->pos);
	sfClock_restart(heal->timer);
}
