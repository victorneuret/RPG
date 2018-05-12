/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skills
*/

#pragma once

#include "render_window.h"
#include "player.h"

#include <stdbool.h>

void draw_dash(win_t *win, player_t *player);
bool init_dash_sprite(skill_tree_t *skill_tree, sfTexture *tex);
