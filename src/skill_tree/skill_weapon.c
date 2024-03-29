/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skill_weapon
*/

#include "player.h"
#include "render_window.h"
#include "stats_menu.h"

void weapon_level_one(win_t *win)
{
	if (win->game->player->skill_point < 1
		|| win->game->stats_menu->skill_tree->skill[1]->level != 0
		|| win->game->player->level < 2)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->dmg += 2;
	win->game->player->skill_point -= 1;
	win->game->stats_menu->skill_tree->skill[1]->level++;
}

void weapon_level_two(win_t *win)
{
	if (win->game->player->skill_point < 3
		|| win->game->stats_menu->skill_tree->skill[1]->level != 1
		|| win->game->player->level < 5)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->dmg += 4;
	win->game->player->skill_point -= 3;
	win->game->stats_menu->skill_tree->skill[1]->level++;
}

void weapon_level_three(win_t *win)
{
	if (win->game->player->skill_point < 5
		|| win->game->stats_menu->skill_tree->skill[1]->level != 2
		|| win->game->player->level < 11)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->dmg += 8;
	win->game->player->skill_point -= 5;
	win->game->stats_menu->skill_tree->skill[1]->level++;
}

void weapon_save(win_t *win, uint8_t level)
{
	if (level >= 1)
		win->game->player->dmg += 2;
	if (level >= 2)
		win->game->player->dmg += 4;
	if (level >= 3)
		win->game->player->dmg += 8;
}
