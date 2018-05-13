/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skill_heal
*/

#include <SFML/Graphics.h>

#include "player.h"
#include "render_window.h"
#include "stats_menu.h"

void heal_level_one(win_t *win)
{
	if (win->game->player->skill_point < 1
		|| win->game->stats_menu->skill_tree->skill[3]->level != 0
		|| win->game->player->level < 2)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->skill_point -= 1;
	win->game->stats_menu->skill_tree->skill[3]->level++;
	win->game->stats_menu->skill_tree->heal.delay_sec = 20;
	win->game->stats_menu->skill_tree->heal.unlocked = true;
	win->game->stats_menu->skill_tree->heal.prct = 0.20f;
}

void heal_level_two(win_t *win)
{
	if (win->game->player->skill_point < 3
		|| win->game->stats_menu->skill_tree->skill[3]->level != 1
		|| win->game->player->level < 5)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->skill_point -= 3;
	win->game->stats_menu->skill_tree->skill[3]->level++;
	win->game->stats_menu->skill_tree->heal.prct = 0.30f;
}

void heal_level_three(win_t *win)
{
	if (win->game->player->skill_point < 5
		|| win->game->stats_menu->skill_tree->skill[3]->level != 2
		|| win->game->player->level < 11)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->skill_point -= 5;
	win->game->stats_menu->skill_tree->skill[3]->level++;
	win->game->stats_menu->skill_tree->heal.prct = 0.40f;
}
