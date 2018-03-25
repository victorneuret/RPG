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

void next_weather(win_t *win);
void previous_weather(win_t *win);
void next_intensity(win_t *win);
void previous_intensity(win_t *win);
void to_title_page(win_t *win);
void joystick_connected(win_t *win, sfEvent *event);
void joystick_disconnected(win_t *win, sfEvent *event);
