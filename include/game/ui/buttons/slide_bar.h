/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** slide_bar
*/

#pragma once

#include <SFML/Graphics.h>

#include <stdint.h>

typedef struct slide_bar {
	sfRectangleShape *rect;
	sfRectangleShape *cursor;
	uint8_t value;
	uint8_t game_state;
} slide_bar_t;

typedef struct slide_bar_def {
	int8_t game_state;
	sfVector2f pos;
	uint32_t clr;
} slide_bar_def_t;

static const slide_bar_def_t slide_bar_def[] = {
	{
		GAME,
		(sfVector2f) {832, 500},
		0xC62828BB
	},
	{
		GAME,
		(sfVector2f) {832, 550},
		0x558B2FBB
	},
	{
		GAME,
		(sfVector2f) {832, 600},
		0x1565C0BB
	},
	{
		ALL,
		(sfVector2f) {0, 0},
		0xFFFFFFF
	}
};

bool init_slide_bar(ui_t *ui);
void draw_slide_bar(ui_t *ui, win_t *win);
void slide_bar_click(slide_bar_t **slide_bar, win_t *win, uint8_t status);
