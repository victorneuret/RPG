/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** key_pressed_functions
*/

#pragma once

#include "render_window.h"

typedef struct render_window win_t;

void close_win(win_t *win);
void toggle_fullscreen(win_t *win);

void toggle_fps(win_t *win);

void pause_game(win_t *win);
void to_title_page(win_t *win);

void open_door(win_t *win);
void add_gun(win_t *win);
void drop_gun(win_t *win);
