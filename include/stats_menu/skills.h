/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** skills
*/

#pragma once

#include "render_window.h"

void hp_level_one(win_t *win);
void hp_level_two(win_t *win);
void hp_level_three(win_t *win);
void hp_save(win_t *win, uint8_t level);

void weapon_level_one(win_t *win);
void weapon_level_two(win_t *win);
void weapon_level_three(win_t *win);
void weapon_save(win_t *win, uint8_t level);

void dash_level_one(win_t *win);
void dash_level_two(win_t *win);
void dash_level_three(win_t *win);
void dash_save(win_t *win, uint8_t level);

void heal_level_one(win_t *win);
void heal_level_two(win_t *win);
void heal_level_three(win_t *win);
void heal_save(win_t *win, uint8_t level);
