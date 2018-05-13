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
		|| win->game->stats_menu->skill_tree->skill[2]->level != 0
		|| win->game->player->level < 2)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->stats_menu->skill_tree->dash->unlocked = true;
	win->game->player->skill_point -= 1;
	win->game->stats_menu->skill_tree->skill[2]->level++;
}

void dash_level_two(win_t *win)
{
	if (win->game->player->skill_point < 3
		|| win->game->stats_menu->skill_tree->skill[2]->level != 1
		|| win->game->player->level < 5)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->stats_menu->skill_tree->dash->distance += 20;
	win->game->player->skill_point -= 3;
	win->game->stats_menu->skill_tree->skill[2]->level++;
}

void dash_level_three(win_t *win)
{
	if (win->game->player->skill_point < 5
		|| win->game->stats_menu->skill_tree->skill[2]->level != 2
		|| win->game->player->level < 11)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->stats_menu->skill_tree->dash->distance += 20;
	win->game->stats_menu->skill_tree->dash->delay -= 2;
	win->game->player->skill_point -= 5;
	win->game->stats_menu->skill_tree->skill[2]->level++;
}

void dash_save(win_t *win, uint8_t level)
{
	if (level >= 1)
		win->game->stats_menu->skill_tree->dash->unlocked = true;
	if (level >= 2)
		win->game->stats_menu->skill_tree->dash->distance += 20;
	if (level >= 3) {
		win->game->stats_menu->skill_tree->dash->distance += 20;
		win->game->stats_menu->skill_tree->dash->delay -= 2;
	}
}
