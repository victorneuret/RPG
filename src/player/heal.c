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
#include "text_utils.h"

static bool init_skill_heal_sprite(win_t *win, heal_t *heal)
{
	sfFont *ft = sfFont_createFromFile("res/fonts/isaac_sans.ttf");

	heal->sprite = sfSprite_copy(
			win->game->stats_menu->skill_tree->dash->sprite);
	if (!heal->sprite || !ft)
		return false;
	heal->text = init_text(ft, "0", (sfVector2f){245, 920}, 30);
	if (!heal->text)
		return false;
	sfText_setStyle(heal->text, sfTextBold);
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
	if (heal->unlocked && sfTime_asSeconds(
		sfClock_getElapsedTime(heal->timer)) >= heal->delay_sec)
		sfSprite_setColor(heal->sprite, hex_to_rgba(0x75FFE7FF));
	else if (heal->unlocked) {
		sfSprite_setColor(heal->sprite, hex_to_rgba(0xE0EDFFC8));
		sfText_setString(heal->text, int_to_str(heal->delay_sec - (int)
			sfTime_asSeconds(sfClock_getElapsedTime(heal->timer))));
		sfRenderWindow_drawText(win->sf_win, heal->text, 0);
	}
	sfRenderWindow_drawSprite(win->sf_win, heal->sprite, 0);
	first = false;
}

void heal_player(win_t *win, heal_t *heal)
{
	const player_t *player = win->game->player;

	if (!heal->unlocked || player->hp->value >= player->hp->max_value)
		return;
	if (sfTime_asSeconds(sfClock_getElapsedTime(heal->timer))
						< heal->delay_sec)
		return;
	particle_heal(win, player->hp->max_value * heal->prct, player->pos);
	sfClock_restart(heal->timer);
}
