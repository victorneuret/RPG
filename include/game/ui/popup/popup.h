/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** popup
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum popup_type {
	INFO,
	WARNING,
	SUCCESS,
	ERROR
} popup_type;

typedef struct popup {
	sfRectangleShape *rect;
	sfText *message;
	sfText *header;
	sfClock *timer;
	uint64_t duration_ms;
	popup_type type;
	bool alive;
} popup_t;

typedef struct popup_list {
	popup_t *popup;
	struct popup_list *next;
} popup_list_t;

typedef struct ui ui_t;
typedef struct render_window win_t;

void create_popup(ui_t *ui, char const *text, popup_type type);
void update_popups(popup_list_t *popups);
void draw_popups(win_t *win, popup_list_t *popups);
void destroy_popup(popup_t *popup);
