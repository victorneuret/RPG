/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skill_dash
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "render_window.h"
#include "stats_menu.h"

void dash_level_one(win_t *win)
{
	if (win->game->player->skill_point < 1
		|| win->game->stats_menu->skill_tree->skill[2]->level != 0)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->stats_menu->skill_tree->dash->unlocked = true;
	win->game->player->skill_point -= 1;
	win->game->stats_menu->skill_tree->skill[3]->level++;
}
