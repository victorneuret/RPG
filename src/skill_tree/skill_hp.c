/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skill_hp
*/

#include "player.h"
#include "render_window.h"
#include "stats_menu.h"
#include "music.h"

void hp_level_one(win_t *win)
{
	if (win->game->player->skill_point < 1
		|| win->game->stats_menu->skill_tree->skill[0]->level != 0
		|| win->game->player->level < 2)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->hp->value += 250;
	win->game->player->hp->max_value += 250;
	win->game->player->skill_point -= 1;
	win->game->stats_menu->skill_tree->skill[0]->level++;
}

void hp_level_two(win_t *win)
{
	if (win->game->player->skill_point < 3
		|| win->game->stats_menu->skill_tree->skill[0]->level != 1
		|| win->game->player->level < 5)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->hp->value += 600;
	win->game->player->hp->max_value += 600;
	win->game->player->skill_point -= 3;
	win->game->stats_menu->skill_tree->skill[0]->level++;
}

void hp_level_three(win_t *win)
{
	if (win->game->player->skill_point < 5
		|| win->game->stats_menu->skill_tree->skill[0]->level != 2
		|| win->game->player->level < 11)
		return;
	play_sfx(win->game->sounds, UNLOCK_SKILL);
	win->game->player->hp->value += 1200;
	win->game->player->hp->max_value += 1200;
	win->game->player->skill_point -= 5;
	win->game->stats_menu->skill_tree->skill[0]->level++;
}
