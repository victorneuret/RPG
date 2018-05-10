/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_skill_tree
*/

#include "stats_menu.h"

static void draw_skill_point(win_t *win, skill_tree_t *skill_tree)
{
	sfSprite_setPosition(skill_tree->sp, (sfVector2f){686, 236});
	sfText_setPosition(skill_tree->nb_sp, (sfVector2f){880, 320});
	sfText_setString(skill_tree->nb_sp, "3");
	sfRenderWindow_drawSprite(win->sf_win, skill_tree->sp, 0);
	sfRenderWindow_drawText(win->sf_win, skill_tree->nb_sp, 0);
	sfSprite_setPosition(skill_tree->sp, (sfVector2f){686, 436});
	sfText_setPosition(skill_tree->nb_sp, (sfVector2f){880, 520});
	sfText_setString(skill_tree->nb_sp, "2");
	sfRenderWindow_drawSprite(win->sf_win, skill_tree->sp, 0);
	sfRenderWindow_drawText(win->sf_win, skill_tree->nb_sp, 0);
	sfSprite_setPosition(skill_tree->sp, (sfVector2f){686, 636});
	sfText_setPosition(skill_tree->nb_sp, (sfVector2f){880, 720});
	sfText_setString(skill_tree->nb_sp, "1");
	sfRenderWindow_drawSprite(win->sf_win, skill_tree->sp, 0);
	sfRenderWindow_drawText(win->sf_win, skill_tree->nb_sp, 0);
}

void draw_skill_tree(win_t *win, stats_menu_t *stats)
{
	sfRenderWindow_drawText(win->sf_win, stats->skill_tree->active, 0);
	sfRenderWindow_drawText(win->sf_win, stats->skill_tree->passive, 0);
	draw_skill_point(win, stats->skill_tree);
}
