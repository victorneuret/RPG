/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** checkbox_functions
*/

#pragma once

#include "render_window.h"
#include "sprite_utils.h"

typedef struct checkbox checkbox_t;
typedef struct render_window win_t;
typedef struct textures textures_t;

/* CheckBox */
void checkbox_click_animation(checkbox_t *checkbox);
void checkbox_click_released(win_t *win, const sfEvent *event);
void checkbox_click_pressed(win_t *win, const sfEvent *event);
checkbox_t *load_checkbox(textures_t *textures);
void free_checkbox(checkbox_t *buttons);
void checkbox_animation(win_t *win);
void draw_checkbox(win_t *win);
void checkbox_click_animation(checkbox_t *checkbox);
sfSprite *get_checkbox_sprite(checkbox_t *checkbox);
void checkbox_fullscreen(win_t *win, checkbox_t *checkbox);
