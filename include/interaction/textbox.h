/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** textbox
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct textbox {
	sfVector2f pos;
	sfRectangleShape *rect;
	sfColor border_color;
	sfColor foreground_color;
	sfText *name;
	sfText *text;
	bool state;
} textbox_t;

textbox_t *init_textbox(void);
