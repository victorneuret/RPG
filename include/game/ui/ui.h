/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** ui
*/

#pragma once

#include "popup.h"
#include "buttons.h"
#include "text_area.h"
#include "title_page.h"

typedef struct buttons buttons_t;
typedef struct checkbox checkbox_t;
typedef struct text_area text_area_t;
typedef struct hover_text_button text_hover_button_t;
typedef struct title_page title_page_t;

typedef struct ui {
	buttons_t *buttons;
	checkbox_t *checkbox;
	text_hover_button_t *hover_text_button;
	text_area_t *text_area;
	title_page_t *title_page;
	popup_list_t *popup_list;
} ui_t;
